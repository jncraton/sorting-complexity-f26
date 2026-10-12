#include "list.hh"

#include <stdexcept>

#include "trackedint.hh"

template <typename T>
list<T>::node::node(const T &value, node *previous, node *next)
    : value(value), previous(previous), next(next) { throw "unimplemented"; }

template <typename T>
list<T>::list() : head(nullptr), tail(nullptr), count(0) { throw "unimplemented"; }

template <typename T>
list<T>::list(std::initializer_list<T> values)
    : head(nullptr), tail(nullptr), count(0) { throw "unimplemented"; }

template <typename T> list<T>::~list() { throw "unimplemented"; }

template <typename T> void list<T>::push_back(const T &value) { throw "unimplemented"; }

template <typename T> void list<T>::push_front(const T &value) { throw "unimplemented"; }

template <typename T> void list<T>::pop_back()     {
  Node* current = tail;
  if (current == nullptr) {
    return;}
  else if (current->prev == nullptr) {
    delete current;
    head = tail = nullptr;
    return;}
  else if (current->prev == head) {
    delete current;
    tail = head;
    head->next = nullptr;
    return;}

  tail = current->prev;
  delete current;
  tail->next = nullptr;
}

template <typename T> void list<T>::pop_front() { throw "unimplemented"; }

template <typename T> void list<T>::insert(std::size_t index, const T &value) { throw "unimplemented"; }

template <typename T> void list<T>::clear() { throw "unimplemented"; }

template <typename T> T &list<T>::at(std::size_t index) { throw "unimplemented"; }

template <typename T> const T &list<T>::at(std::size_t index) const { throw "unimplemented"; }

template <typename T> T &list<T>::operator[](std::size_t index) {
  return at(index);
}

template <typename T> const T &list<T>::operator[](std::size_t index) const {
  return at(index);
}

template <typename T> T &list<T>::front() { throw "unimplemented"; }

template <typename T> const T &list<T>::front() const { throw "unimplemented"; }

template <typename T> T &list<T>::back() { throw "unimplemented"; }

template <typename T> const T &list<T>::back() const { throw "unimplemented"; }

template <typename T> std::size_t list<T>::size() const { throw "unimplemented"; }

template <typename T> void list<T>::sort_bubble() { throw "unimplemented"; }

template <typename T> void list<T>::sort_insertion() { throw "unimplemented"; }

template <typename T> void list<T>::sort_selection() { throw "unimplemented"; }

template <typename T> void list<T>::sort_merge() { throw "unimplemented"; }

template <typename T> void list<T>::sort_quick() { throw "unimplemented"; }

template <typename T> void list<T>::sort_heap() { throw "unimplemented"; }

template <typename T> void list<T>::sort_shell() { throw "unimplemented"; }

template <typename T> void list<T>::sort_tim() { throw "unimplemented"; }

template class list<TrackedInt>;
template class list<int>;
