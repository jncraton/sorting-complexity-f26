#pragma once

#include <cstddef>
#include <initializer_list>

template <typename T> class forward_list {
  struct node {
    T value;
    node *next;

    node(const T &value, node *next = nullptr);
  };

  node *head;
  std::size_t count;

public:
  forward_list();
  forward_list(std::initializer_list<T> values);
  ~forward_list();

  forward_list(const forward_list &) = delete;
  forward_list &operator=(const forward_list &) = delete;
  forward_list(forward_list &&) = delete;
  forward_list &operator=(forward_list &&) = delete;

  void push_back(const T &value);
  if (head == nullptr) {
    head = new Node(value);
    return;
  }
  Node* current = head;
  while (current->next != nullptr) {
    current = current->next;
  }
  current->next = new Node(value);}

  void push_front(const T &value);
  void pop_back(); {
    if (head == nullptr) {
      throw std::out_of_range("List is empty");
    }

    if (head->next == nullptr) {
      delete head;
      head = nullptr;
      return;
    }

    Node *current = head;
    while (current->next->next != nullptr) {
      current = current->next;
    }
    delete current->next;
    current->next = nullptr;
  void pop_front();
  void insert(std::size_t index, const T &value) {
    if (index == 0) {
      head = new Node(&value, head);
      return;
    }
    Node* current = head;
      for (int i = 0; i < index - 1 && current != nullptr; ++i) {
      current = current->next;
    }
      if (current != nullptr) {
      current->next = new Node(&value, current->next);
    }


  void clear();

  T &at(std::size_t index);
  const T &at(std::size_t index) const;
  T &operator[](std::size_t index);
  const T &operator[](std::size_t index) const;
  T &front();
  const T &front() const;
  T &back();
  const T &back() const;
  std::size_t size() const;

  void sort_bubble();
  void sort_insertion();
  void sort_selection();
  void sort_merge();
  void sort_quick();
  void sort_heap();
  void sort_shell();
  void sort_tim();
};
