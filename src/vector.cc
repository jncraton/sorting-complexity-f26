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

template <typename T> vector<T>::~vector() {
  delete[] data_ptr;
}
//im doing this one
template <typename T> void vector<T>::push_back(const T &value) {
   if (count >= cap){
     reallocate(cap == 0 ? 1 : cap * 2);
   }
   
  data_ptr[count] = value;
  count++;
   }
//im also doing this one.
template <typename T> void vector<T>::push_front(const T &value) { 
  if (count >= cap){
    reallocate(cap == 0 ? 1 : cap * 2);
  } 

  for (std::size_t i = count; i > 0; i--){
    data_ptr[i] = data_ptr[i - 1]; 
  }
  data_ptr[0] = value;
  count++;
}
//im going to try adn do this one just because
template <typename T> void vector<T>::pop_back() {
    if (count == 0)
    {
      throw std::out_of_range("pop_back on empty vector");
    }
    count--;
    

  }
//this one as well
template <typename T> void vector<T>::pop_front() {
    if (count == 0){
      throw std::out_of_range("pop_front on empty vector");
    }
    for(std::size_t i = 0; i + 1 < count; i++ ){
      data_ptr[i] = data_ptr[i+1];
    }
    count--;
 }
//and this one
template <typename T>
void vector<T>::insert(std::size_t index, const T &value) {
  if (index > count) {
    throw std::out_of_range("Index out of bounds");
  }  
  if (count >= cap) {
      reallocate(cap == 0 ? 1 : cap * 2);
  }
  for(std::size_t i = count; i > index; i--) {
        data_ptr[i] = data_ptr[i-1];
  }
    data_ptr[index] = value; 
    count++;
 }

template <typename T> void vector<T>::clear() { 
    count = 0;
 }

template <typename T> T &vector<T>::at(std::size_t index) {
  if(index >= count){
    throw std::out_of_range("index out of range");
  }
  return data_ptr[index];
 }

template <typename T> const T &vector<T>::at(std::size_t index) const {
   if(index >= count){
    throw std::out_of_range("index out of range");
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
    throw std::out_of_range("vector::front on empty vector");
  }
  return data_ptr[0];
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

template <typename T> std::size_t vector<T>::size() const { return count; }

template <typename T> void vector<T>::sort_bubble() {
  for (std::size_t end = count; end > 1; end--) {
    bool swapped = false;
    for (std::size_t i = 0; i + 1 < end; i++) {
      if (data_ptr[i] > data_ptr[i + 1]) {
        std::swap(data_ptr[i], data_ptr[i + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

template <typename T> void vector<T>::sort_insertion() { throw "unimplemented"; }

template <typename T> void vector<T>::sort_selection() {
      
        for(int i = 0; i < count-1; i++){
          int largest = 0;
          for(int j = 1; j < count - i; j++){

           
          if(data_ptr[j] > data_ptr[largest]){
            largest = j;
          }
        }
        std::swap(data_ptr[j], data_ptr[count - i - 1]);
      }

 }

template <typename T> void vector<T>::sort_merge() { throw "unimplemented"; }
template <typename T> void vector<T>::sort_quick() { throw "unimplemented"; }
template <typename T> void vector<T>::sort_heap() { throw "unimplemented"; }
template <typename T> void vector<T>::sort_shell() { throw "unimplemented"; }
template <typename T> void vector<T>::sort_tim() { throw "unimplemented"; }

template class vector<TrackedInt>;
template class vector<int>;
