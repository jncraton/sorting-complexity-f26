#include "forward_list.hh"

#include <stdexcept>

#include "trackedint.hh"

template <typename T>
forward_list<T>::node::node(const T &value, node *next)
    : value(value), next(next) { throw "unimplemented"; }

template <typename T>
forward_list<T>::forward_list() : head(nullptr), count(0) { throw "unimplemented"; }

template <typename T>
forward_list<T>::forward_list(std::initializer_list<T> values)
    : head(nullptr), count(0) { throw "unimplemented"; }

template <typename T> forward_list<T>::~forward_list() { throw "unimplemented"; }

template <typename T> void forward_list<T>::push_back(const T &value)
{
if (head == nullptr) {
    head = new node(value);
    return;
  }
  node* current = head;
  while (current->next != nullptr) {
    current = current->next;
  }
  current->next = new node(value);}

template <typename T> void forward_list<T>::push_front(const T &value)
{
node* newNode = new node(value);


    if (head == nullptr) {
      head = newNode;
      return;


    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }

template <typename T> void forward_list<T>::pop_back()
{
if (head == nullptr) {
      throw std::out_of_range("List is empty");
    }

    if (head->next == nullptr) {
      delete head;
      head = nullptr;
      return;
    }

    node *current = head;
    while (current->next->next != nullptr) {
      current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

template <typename T> void forward_list<T>::pop_front() { throw "unimplemented"; }

template <typename T> void forward_list<T>::insert(std::size_t index, const T &value) 
{
if (index == 0) {
      head = new node(&value, head);
      return;
    }
    node* current = head;
      for (int i = 0; i < index - 1 && current != nullptr; ++i) {
      current = current->next;
    }
      if (current != nullptr) {
      current->next = new node(&value, current->next);
    }
}

template <typename T> void forward_list<T>::clear()
{
  node* current = head;
    while (current != nullptr) {
      node* next = current->next;
      delete current;
      current = next;
    }
    head = nullptr;
}


template <typename T> T &forward_list<T>::at(std::size_t index) { throw "unimplemented"; }

template <typename T> const T &forward_list<T>::at(std::size_t index) const { throw "unimplemented"; }

template <typename T> T &forward_list<T>::operator[](std::size_t index) {
  return at(index);
}

template <typename T>
const T &forward_list<T>::operator[](std::size_t index) const {
  return at(index);
}

template <typename T> T &forward_list<T>::front() { throw "unimplemented"; }

template <typename T> const T &forward_list<T>::front() const { throw "unimplemented"; }

template <typename T> T &forward_list<T>::back() { throw "unimplemented"; }

template <typename T> const T &forward_list<T>::back() const { throw "unimplemented"; }

template <typename T> std::size_t forward_list<T>::size() const { throw "unimplemented"; }

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
