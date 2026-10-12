#include "vector.hh"

#include <algorithm>
#include <stdexcept>

#include "trackedint.hh"

template <typename T> void vector<T>::reallocate(std::size_t new_cap) { throw "unimplemented"; }

template <typename T>
vector<T>::vector() : data_ptr(nullptr), count(0), cap(0) { throw "unimplemented"; }

template <typename T>
vector<T>::vector(std::initializer_list<T> values)
    : data_ptr(nullptr), count(0), cap(0) { throw "unimplemented"; }

template <typename T> vector<T>::~vector() { throw "unimplemented"; }

template <typename T> void vector<T>::push_back(const T &value) { throw "unimplemented"; }

template <typename T> void vector<T>::push_front(const T &value) { throw "unimplemented"; }

template <typename T> void vector<T>::pop_back() { throw "unimplemented"; }

template <typename T> void vector<T>::pop_front() { throw "unimplemented"; }

template <typename T>
void vector<T>::insert(std::size_t index, const T &value) { throw "unimplemented"; }

template <typename T> void vector<T>::clear() { throw "unimplemented"; }

template <typename T> T &vector<T>::at(std::size_t index) { throw "unimplemented"; }

template <typename T> const T &vector<T>::at(std::size_t index) const { throw "unimplemented"; }

template <typename T> T &vector<T>::operator[](std::size_t index) {
  return data_ptr[index];
}

template <typename T> const T &vector<T>::operator[](std::size_t index) const {
  return data_ptr[index];
}

template <typename T> T &vector<T>::front() { throw "unimplemented"; }

template <typename T> const T &vector<T>::front() const { throw "unimplemented"; }

template <typename T> T &vector<T>::back() { throw "unimplemented"; }

template <typename T> const T &vector<T>::back() const { throw "unimplemented"; }

template <typename T> std::size_t vector<T>::size() const { throw "unimplemented"; }

template <typename T> void vector<T>::sort_bubble() { throw "unimplemented"; }

template <typename T> void vector<T>::sort_insertion() { throw "unimplemented"; }

template <typename T> void vector<T>::sort_selection() { throw "unimplemented"; }

template <typename T> void vector<T>::sort_merge() { throw "unimplemented"; }
template <typename T> void vector<T>::sort_quick() { throw "unimplemented"; }
template <typename T> void vector<T>::sort_heap() { throw "unimplemented"; }
template <typename T> void vector<T>::sort_shell() { throw "unimplemented"; }
template <typename T> void vector<T>::sort_tim() { throw "unimplemented"; }

template class vector<TrackedInt>;
template class vector<int>;
