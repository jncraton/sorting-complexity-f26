
import csv
from collections import defaultdict
from pathlib import Path

import plotly.graph_objects as go


INPUT_ORDER_RANK = {
    "presorted": 0,
    "reverse_sorted": 1,
    "randomized": 2,
}


def load_results(filename):
    """Read benchmark rows from a CSV file."""
    with open(filename, newline="", encoding="utf-8") as csvfile:
        rows = list(csv.DictReader(csvfile))

    required = {
        "container",
        "operation",
        "size",
        "iterations",
        "ns_per_operation",
    }

    if not rows or not required.issubset(rows[0]):
        raise ValueError("CSV must contain the required benchmark columns")

    for row in rows:
        row["size"] = int(row["size"])
        row["iterations"] = int(row["iterations"])
        row["ns_per_operation"] = float(row["ns_per_operation"])
        row["input_order"] = row.get("input_order") or "presorted"

    return rows


def build_chart(rows):
    """Create an interactive sorting comparison dashboard."""

    groups = defaultdict(list)

    for row in rows:
        key = (
            row["operation"],
            row["input_order"],
            row["container"],
        )
        groups[key].append(row)

    containers = sorted({row["container"] for row in rows})

    combinations = {
        (row["operation"], row["input_order"])
        for row in rows
    }

    combinations = sorted(
        combinations,
        key=lambda item: (
            item[0],
            INPUT_ORDER_RANK.get(item[1], 99),
            item[1],
        ),
    )

    fig = go.Figure()

    combination_traces = defaultdict(list)

    for operation, input_order in combinations:

        for container in containers:

            points = sorted(
                groups.get((operation, input_order, container), []),
                key=lambda row: row["size"],
            )

            if not points:
                continue

            trace_index = len(fig.data)

            combination_traces[(operation, input_order)].append(
                trace_index
            )

            fig.add_trace(
                go.Scatter(
                    x=[row["size"] for row in points],
                    y=[row["ns_per_operation"] for row in points],
                    mode="lines+markers",
                    name=container,
                    legendgroup=container,
                    visible=(operation, input_order) == combinations[0],
                    customdata=[
                        [
                            row["iterations"],
                            row["input_order"],
                            row["operation"],
                            row["container"],
                        ]
                        for row in points
                    ],
                    hovertemplate=(
                        "<b>%{customdata[3]}</b><br>"
                        "Algorithm: %{customdata[2]}<br>"
                        "Input size: %{x}<br>"
                        "Nanoseconds/operation: %{y}<br>"
                        "Iterations: %{customdata[0]}<br>"
                        "Input order: %{customdata[1]}"
                        "<extra></extra>"
                    ),
                )
            )

    buttons = []

    for operation, input_order in combinations:

        visible = [False] * len(fig.data)

        for index in combination_traces[(operation, input_order)]:
            visible[index] = True

        buttons.append(
            {
                "label": f"{operation} / {input_order}",
                "method": "update",
                "args": [
                    {"visible": visible},
                    {
                        "title": (
                            f"{operation} ({input_order}): "
                            "Sorting Performance Comparison"
                        )
                    },
                ],
            }
        )

    first_operation, first_input_order = combinations[0]

    fig.update_layout(
        title=(
            f"{first_operation} ({first_input_order}): "
            "Sorting Performance Comparison"
        ),
        xaxis_title="Input Size",
        yaxis_title="Nanoseconds per Operation",
        xaxis_type="log",
        yaxis_type="log",
        template="plotly_white",
        hovermode="x unified",
        legend_title="Container",
        updatemenus=[
            {
                "buttons": buttons,
                "direction": "down",
                "showactive": True,
                "x": 0,
                "xanchor": "left",
                "y": 1.15,
                "yanchor": "top",
            }
        ],
        margin={"t": 120},
    )

    return fig


def main():
    rows = load_results("bench.csv")

    fig = build_chart(rows)

    fig.write_html(
        "index.html",
        full_html=True,
        include_plotlyjs=True,
    )

    print(f"Wrote {Path('index.html').resolve()}")


if __name__ == "__main__":
    main()