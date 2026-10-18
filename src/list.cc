#include "list.hh"

#include <stdexcept>

#include "trackedint.hh"

template <typename T>
list<T>::node::node(const T &value, node *prev, node *next)
    : value(value), prev(prev), next(next) {}

template <typename T>
list<T>::list() : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
list<T>::list(std::initializer_list<T> values)
    : head(nullptr), tail(nullptr), count(0) {
      for (const T& value : values){
        push_back(value);}
    }

template <typename T> list<T>::~list() {
  clear();}

template <typename T> void list<T>::push_back(const T &value) { 
  if (tail == nullptr){
    head = tail = new Node(value, nullptr, nullptr);}
  else if (tail == head) {
    head->next = tail = new Node(value, head, nullptr);}
  else {
    tail = tail->next = new Node(value, tail, nullptr);}
  
  count++;
}

template <typename T> void list<T>::push_front(const T &value) { 
  if (head == nullptr) {
    head = tail = new Node(value, nullptr, nullptr);}
  else if (head == tail){
    tail->prev = head = new Node(value, nullptr, tail);}
  else {
    head = head->prev = new Node(value, nullptr, head);}
  
  count++;
 }

template <typename T> void list<T>::pop_back()     {
  Node* current = tail;

  if (current == nullptr) {
    return;}  

  count--;
  
  if (current->prev == nullptr) {
    delete current;
    head = tail = nullptr;
    return;}
  else if (current->prev == head) {
    delete current;
    tail = head;
    head->next = nullptr;
    return;}
  else {
    tail = current->prev;
    delete current;
    tail->next = nullptr;}
}

template <typename T> void list<T>::pop_front() { 
  Node* current = head;

  if (current == nullptr) {
    return;}
    
  count--;
  
  if (current == tail) {
    delete current;
    head = tail = nullptr;}
  else {
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;}
 }

template <typename T> void list<T>::insert(std::size_t index, const T &value) {
  int i = 0;
  Node* current = head;

  if (index == 0) {
    push_front(value);
    return;}

  while (i < index - 1 && current != nullptr) {
    current = current->next;
    i++;}

  if (current == nullptr) {
      throw std::out_of_range("Index out of range");}
  if (current == tail){
    push_back(value);}
  else{
    current->next = new Node(value, current, current->next);
    current->next->next->prev = current->next;
    count++;}
}

template <typename T> void list<T>::clear() {
  Node* current = tail;

  if (current == nullptr){
    return;}

  while (current != head){
    node* temp = current;
    current = current->next;
    delete temp;}

  head = tail = nullptr;  
  count = 0;
}

template <typename T> T &list<T>::at(std::size_t index) { 
  int i = 0;
  Node* current = head;

  if (current == nullptr) {
      throw std::out_of_range("Index out of range");}
    while (i < index){
      if (current->next == nullptr) {
        throw std::out_of_range("Index out of range");}
      current = current->next;
      i++;}
    
  return current->value;
}

template <typename T> const T &list<T>::at(std::size_t index) const { 
  int i = 0;
  const Node* current = head;

  if (current == nullptr) {
      throw std::out_of_range("Index out of range");}
    while (i < index){
      if (current->next == nullptr) {
        throw std::out_of_range("Index out of range");}
      current = current->next;
      i++;}
    
  return current->value;
}

template <typename T> T &list<T>::operator[](std::size_t index) {
  return at(index);
}

template <typename T> const T &list<T>::operator[](std::size_t index) const {
  return at(index);
}

template <typename T> T &list<T>::front() {
  if (head == nullptr){
    throw std::out_of_range("List is empty");}
  else{
    return head->value;}
}

template <typename T> const T &list<T>::front() const { 
  if (head == nullptr){
    throw std::out_of_range("List is empty");}
  else{
    return head->value;}
}

template <typename T> T &list<T>::back() { 
  if (tail == nullptr){
      throw std::out_of_range("List is empty");}
    else{
      return tail->value;}
}

template <typename T> const T &list<T>::back() const {
  if (tail == nullptr){
    throw std::out_of_range("List is empty");}
  else{
    return tail->value;}
}

template <typename T> std::size_t list<T>::size() const {
  return count;
}

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
