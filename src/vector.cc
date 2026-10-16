#include "vector.hh"

#include <algorithm>
#include <stdexcept>

#include "trackedint.hh"

template <typename T> void vector<T>::reallocate(std::size_t new_cap) {
  T *new_data = new T[new_cap];
  for (std::size_t i = 0; i < count; ++i) {
    new_data[i] = data_ptr[i];
  }
  delete[] data_ptr;
  data_ptr = new_data;
  cap = new_cap;
 }

template <typename T>
vector<T>::vector() 
: data_ptr(nullptr), count(0), cap(0) {
}

template <typename T>
vector<T>::vector(std::initializer_list<T> values)
    : data_ptr(nullptr), count(0), cap(0) { 
  for (const T& value : values) {
      push_back(value);
  }
    }

template <typename T> vector<T>::~vector() { throw "unimplemented"; }
//im doing this one
template <typename T> void vector<T>::push_back(const T &value) {
   if (count >= cap){
     reallocate(cap*2);
   }
   
  data_ptr[count] = value;
  count++;
   }
//im also doing this one.
template <typename T> void vector<T>::push_front(const T &value) { 
  if (count >= cap){
    reallocate(cap*2);
  } 
  if (count = 0){
    data_ptr[0] = value;
  }
  std::size_t i = count;
  while( i > 0){
    data_ptr[i] = data_ptr[i - 1];
    i--;  
  }
  data_ptr[0] = value;
  count++;
}
//im going to try adn do this one just because
template <typename T> void vector<T>::pop_back() {
    if (count == 0)
    {
      std::out_of_range("This list does not exist");
    }
    count--;
    

  }
//this one as well
template <typename T> void vector<T>::pop_front() {
    if (count == 0){
      std::out_of_range("This lsit does not exist");
    }
    if (count == 1){
      count--;
    }
    std::size_t index = 0;
    for(std::size_t i = index; i + 1 < count; i++ ){
      data_ptr[i] = data_ptr[i+1];
    }

 }
//and this one
template <typename T>
void vector<T>::insert(std::size_t index, const T &value) {
    if (size >= cap) {
      resize(cap*2);
    }
    if (index < count && index >= 0){
      for(std::size_t i = count; i > index; i--){
        data_ptr[i] = data_ptr[i-1];
      }
      data_ptr[index] = value; 
    }
    else {
      throw std::out_of_range("Index out of bounds");
    }
    count++;

 }

template <typename T> void vector<T>::clear() { 
    count = 0;
 }

template <typename T> T &vector<T>::at(std::size_t index) {
  if(index < 0 || static_cast<std::size_t>(index) >= count){
    throw std::out_of_range{"The item you have selected is out of range"};
  }
  return data_ptr[index];
 }

template <typename T> const T &vector<T>::at(std::size_t index) const {
   if(index < 0 || static_cast<std::size_t>(index) >= count){
    throw std::out_of_range{"The item you have selected is out of range"};
  }
  return data_ptr[index];
 }

template <typename T> T &vector<T>::operator[](std::size_t index) {
  return data_ptr[index];
}

template <typename T> const T &vector<T>::operator[](std::size_t index) const {
  return data_ptr[index];
}

template <typename T> T &vector<T>::front() {
  if (count == 0) {
    throw std::out_of_range("vector::back on empty vector");
  }
  return data_ptr[count - 1];
}

template <typename T> const T &vector<T>::front() const {
  if (count == 0) {
    throw std::out_of_range("vector::front on empty vector");
  }
  return data_ptr[0];
}

template <typename T> T &vector<T>::back() {
  if (count == 0) {
    throw std::out_of_range("vector::back on empty vector");
  }
  return data_ptr[count - 1];
}

template <typename T> const T &vector<T>::back() const {
  if (count == 0) {
    throw std::out_of_range("vector::back on empty vector");
  }
  return data_ptr[count - 1];
}

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
