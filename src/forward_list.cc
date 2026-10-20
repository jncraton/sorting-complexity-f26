#include "forward_list.hh"

#include <stdexcept>

#include "trackedint.hh"

template <typename T>
forward_list<T>::node::node(const T &value, node *next)
    : value(value), next(next) {}

template <typename T>
forward_list<T>::forward_list() : head(nullptr), count(0) {}

template <typename T>
forward_list<T>::forward_list(std::initializer_list<T> values)
    : head(nullptr), count(0) {
  for (const auto &val : values) {
    push_back(val);
  }
}

template <typename T> forward_list<T>::~forward_list() {
  node *curr = head;
  while (curr != nullptr) {
    node *next = curr->next;
    delete curr;
    curr = next;
  }
}

template <typename T> void forward_list<T>::push_back(const T &value) {
  if (head == nullptr) {
    head = new node(value, nullptr);
  } else {
    node *curr = head;
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    curr->next = new node(value, nullptr);
  }
  count++;
}

template <typename T> void forward_list<T>::push_front(const T &value) {
  head = new node(value, head);
  count++;
}

template <typename T> void forward_list<T>::pop_back() {
  if (head == nullptr) {
    throw std::out_of_range("pop_back on empty list");
  }
  if (head->next == nullptr) {
    delete head;
    head = nullptr;
  } else {
    node *curr = head;
    while (curr->next->next != nullptr) {
      curr = curr->next;
    }
    delete curr->next;
    curr->next = nullptr;
  }
  count--;
}

template <typename T> void forward_list<T>::pop_front() {
  if (head == nullptr) {
    throw std::out_of_range("pop_front on empty list");
  }
  node *temp = head;
  head = head->next;
  delete temp;
  count--;
}

template <typename T>
void forward_list<T>::insert(std::size_t index, const T &value) {
  if (index > count) {
    throw std::out_of_range("index out of range");
  }
  if (index == 0) {
    push_front(value);
  } else if (index == count) {
    push_back(value);
  } else {
    node *curr = head;
    for (std::size_t i = 0; i < index - 1; ++i) {
      curr = curr->next;
    }
    curr->next = new node(value, curr->next);
    count++;
  }
}

template <typename T> void forward_list<T>::clear() {
  node *curr = head;
  while (curr != nullptr) {
    node *next = curr->next;
    delete curr;
    curr = next;
  }
  head = nullptr;
  count = 0;
}

template <typename T> T &forward_list<T>::at(std::size_t index) {
  if (index >= count) {
    throw std::out_of_range("index out of range");
  }
  node *curr = head;
  for (std::size_t i = 0; i < index; ++i) {
    curr = curr->next;
  }
  return curr->value;
}

template <typename T> const T &forward_list<T>::at(std::size_t index) const {
  if (index >= count) {
    throw std::out_of_range("index out of range");
  }
  node *curr = head;
  for (std::size_t i = 0; i < index; ++i) {
    curr = curr->next;
  }
  return curr->value;
}

template <typename T> T &forward_list<T>::operator[](std::size_t index) {
  return at(index);
}

template <typename T>
const T &forward_list<T>::operator[](std::size_t index) const {
  return at(index);
}

template <typename T> T &forward_list<T>::front() {
  if (head == nullptr) {
    throw std::out_of_range("front of empty list");
  }
  return head->value;
}

template <typename T> const T &forward_list<T>::front() const {
  if (head == nullptr) {
    throw std::out_of_range("front of empty list");
  }
  return head->value;
}

template <typename T> T &forward_list<T>::back() {
  if (head == nullptr) {
    throw std::out_of_range("back of empty list");
  }
  node *curr = head;
  while (curr->next != nullptr) {
    curr = curr->next;
  }
  return curr->value;
}

template <typename T> const T &forward_list<T>::back() const {
  if (head == nullptr) {
    throw std::out_of_range("back of empty list");
  }
  node *curr = head;
  while (curr->next != nullptr) {
    curr = curr->next;
  }
  return curr->value;
}

template <typename T> std::size_t forward_list<T>::size() const {
  return count;
}

template <typename T> void forward_list<T>::sort_bubble() { throw "unimplemented"; }

template <typename T> void forward_list<T>::sort_insertion() { throw "unimplemented"; }

template <typename T> void forward_list<T>::sort_selection() { throw "unimplemented"; }

template <typename T> void forward_list<T>::sort_merge() { throw "unimplemented"; }
template <typename T> void forward_list<T>::sort_quick() { throw "unimplemented"; }
template <typename T> void forward_list<T>::sort_heap() { throw "unimplemented"; }
template <typename T> void forward_list<T>::sort_shell() { throw "unimplemented"; }
template <typename T> void forward_list<T>::sort_tim() { throw "unimplemented"; }

template class forward_list<TrackedInt>;
template class forward_list<int>;
