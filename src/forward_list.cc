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
    : head(nullptr), count(0)
{
  node **tail = &head;
  for (const T &value : values) {
    *tail = new node(value);
    tail = &((*tail)->next);
    ++count;
  }
}

template <typename T> forward_list<T>::~forward_list() { clear(); }

template <typename T> void forward_list<T>::push_back(const T &value)
{
  node *new_node = new node(value);
  if (head == nullptr) {
    head = new_node;
  } else {
    node *current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new_node;
  }
  ++count;
}

template <typename T> void forward_list<T>::push_front(const T &value)
{
  head = new node(value, head);
  ++count;
}

template <typename T> void forward_list<T>::pop_back()
{
  if (head == nullptr) {
    throw std::out_of_range("List is empty");
  }

  if (head->next == nullptr) {
    delete head;
    head = nullptr;
  } else {
    node *current = head;
    while (current->next->next != nullptr) {
      current = current->next;
    }
    delete current->next;
    current->next = nullptr;
  }
  --count;
}

template <typename T> void forward_list<T>::pop_front()
{
  if (head == nullptr) {
    throw std::out_of_range("List is empty");
  }

  node *old_head = head;
  head = head->next;
  delete old_head;
  --count;
}

template <typename T>
void forward_list<T>::insert(std::size_t index, const T &value)
{
  if (index > count) {
    throw std::out_of_range("Index out of range");
  }

  if (index == 0) {
    push_front(value);
    return;
  }

  node *current = head;
  for (std::size_t i = 0; i < index - 1; ++i) {
    current = current->next;
  }
  current->next = new node(value, current->next);
  ++count;
}

template <typename T> void forward_list<T>::clear()
{
  node *current = head;
  while (current != nullptr) {
    node *next = current->next;
    delete current;
    current = next;
  }
  head = nullptr;
  count = 0;
}

template <typename T> T &forward_list<T>::at(std::size_t index)
{
  if (index >= count) {
    throw std::out_of_range("Index out of range");
  }

  node *current = head;
  for (std::size_t i = 0; i < index; ++i) {
    current = current->next;
  }
  return current->value;
}

template <typename T>
const T &forward_list<T>::at(std::size_t index) const
{
  if (index >= count) {
    throw std::out_of_range("Index out of range");
  }

  const node *current = head;
  for (std::size_t i = 0; i < index; ++i) {
    current = current->next;
  }
  return current->value;
}

template <typename T> T &forward_list<T>::front()
{
  if (head == nullptr) {
    throw std::out_of_range("List is empty");
  }
  return head->value;
}

template <typename T> const T &forward_list<T>::front() const
{
  if (head == nullptr) {
    throw std::out_of_range("List is empty");
  }
  return head->value;
}

template <typename T> T &forward_list<T>::back()
{
  if (head == nullptr) {
    throw std::out_of_range("List is empty");
  }

  node *current = head;
  while (current->next != nullptr) {
    current = current->next;
  }
  return current->value;
}

template <typename T> const T &forward_list<T>::back() const
{
  if (head == nullptr) {
    throw std::out_of_range("List is empty");
  }

  const node *current = head;
  while (current->next != nullptr) {
    current = current->next;
  }
  return current->value;
}

template <typename T> std::size_t forward_list<T>::size() const
{
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
template <typename T> T &forward_list<T>::operator[](std::size_t index) {
  return at(index);
}

template <typename T>
const T &forward_list<T>::operator[](std::size_t index) const {
  return at(index);
}


template class forward_list<TrackedInt>;
template class forward_list<int>;
