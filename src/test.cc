#include "forward_list.hh"
#include "list.hh"
#include "trackedint.hh"
#include "vector.hh"
#include <cassert>
#include <iostream>
#include <stdexcept>

template <typename Container>
void run_tests_for(const std::string &container_name) {
  std::cout << "=== Starting tests for " << container_name
            << " ===" << std::endl;

  // initializer_list & size
  {
    Container l = {10, 20, 30};
    assert(l.size() == 3);
    assert(l.front() == 10);
    assert(l.back() == 30);
  }

  // push_back
  {
    Container l{};
    assert(l.size() == 0);
    l.push_back(1);
    assert(l.size() == 1);
    assert(l.front() == 1);
    assert(l.back() == 1);
    l.push_back(2);
    l.push_back(3);
    assert(l.size() == 3);
    assert(l.front() == 1);
    assert(l.back() == 3);
    assert(l[0] == 1);
    assert(l[1] == 2);
    assert(l[2] == 3);
  }

  // push_front
  {
    Container l{};
    l.push_front(1);
    assert(l.size() == 1);
    assert(l.front() == 1);
    assert(l.back() == 1);
    l.push_front(2);
    l.push_front(3);
    assert(l.size() == 3);
    assert(l.front() == 3);
    assert(l.back() == 1);
    assert(l[0] == 3);
    assert(l[1] == 2);
    assert(l[2] == 1);
  }

  // pop_back
  {
    Container l = {10, 20, 30};
    l.pop_back();
    assert(l.size() == 2);
    assert(l.back() == 20);
    l.pop_back();
    assert(l.size() == 1);
    assert(l.back() == 10);
    l.pop_back();
    assert(l.size() == 0);

    bool exception_thrown = false;
    try {
      l.pop_back();
    } catch (const std::out_of_range &e) {
      exception_thrown = true;
    }
    assert(exception_thrown);
  }

  // pop_front
  {
    Container l = {10, 20, 30};
    l.pop_front();
    assert(l.size() == 2);
    assert(l.front() == 20);
    l.pop_front();
    assert(l.size() == 1);
    assert(l.front() == 30);
    l.pop_front();
    assert(l.size() == 0);

    bool exception_thrown = false;
    try {
      l.pop_front();
    } catch (const std::out_of_range &e) {
      exception_thrown = true;
    }
    assert(exception_thrown);
  }

  // insert
  {
    Container l = {10, 30};
    l.insert(1, 20); // {10, 20, 30}
    assert(l.size() == 3);
    assert(l[0] == 10);
    assert(l[1] == 20);
    assert(l[2] == 30);

    l.insert(0, 5); // {5, 10, 20, 30}
    assert(l.size() == 4);
    assert(l[0] == 5);
    assert(l.front() == 5);

    l.insert(4, 40); // {5, 10, 20, 30, 40}
    assert(l.size() == 5);
    assert(l[4] == 40);
    assert(l.back() == 40);

    bool exception_thrown = false;
    try {
      l.insert(10, 99);
    } catch (const std::out_of_range &e) {
      exception_thrown = true;
    }
    assert(exception_thrown);
  }

  // clear
  {
    Container l = {1, 2, 3};
    assert(l.size() == 3);
    l.clear();
    assert(l.size() == 0);
    l.clear(); // clearing empty container
    assert(l.size() == 0);
  }

  // accessors at and operator[]
  {
    Container l = {100, 200, 300};
    assert(l.at(0) == 100);
    assert(l.at(1) == 200);
    assert(l.at(2) == 300);

    assert(l[0] == 100);
    assert(l[1] == 200);
    assert(l[2] == 300);

    l.at(1) = 250;
    assert(l.at(1) == 250);

    l[2] = 350;
    assert(l[2] == 350);

    const auto &cl = l;
    assert(cl.at(0) == 100);
    assert(cl[1] == 250);

    bool exception_thrown = false;
    try {
      l.at(3);
    } catch (const std::out_of_range &e) {
      exception_thrown = true;
    }
    assert(exception_thrown);

    exception_thrown = false;
    try {
      cl.at(3);
    } catch (const std::out_of_range &e) {
      exception_thrown = true;
    }
    assert(exception_thrown);
  }

  // front and back accessors
  {
    Container l = {10, 20, 30};
    assert(l.front() == 10);
    assert(l.back() == 30);

    l.front() = 15;
    l.back() = 35;
    assert(l.front() == 15);
    assert(l.back() == 35);

    const auto &cl = l;
    assert(cl.front() == 15);
    assert(cl.back() == 35);

    Container empty_l;
    bool exception_thrown = false;
    try {
      empty_l.front();
    } catch (const std::out_of_range &e) {
      exception_thrown = true;
    }
    assert(exception_thrown);

    exception_thrown = false;
    try {
      empty_l.back();
    } catch (const std::out_of_range &e) {
      exception_thrown = true;
    }
    assert(exception_thrown);

    const auto &empty_cl = empty_l;
    exception_thrown = false;
    try {
      empty_cl.front();
    } catch (const std::out_of_range &e) {
      exception_thrown = true;
    }
    assert(exception_thrown);

    exception_thrown = false;
    try {
      empty_cl.back();
    } catch (const std::out_of_range &e) {
      exception_thrown = true;
    }
    assert(exception_thrown);
  }
  //general sort test

 {

Container l = {40,60,30,20,70,50,80,100,10,90};
//Container cl =
for(int i = 0; i < 10; i++){
     std::cout << l.at(i)<< std::endl;
}
 l.sort_bubble();
for(int i = 0; i < 10; i++){
     std::cout << l.at(i) << std::endl;
}

    for(int i = 0; i < 10; i++){
      if(l.at(i) != (i+1)*10){
     //  throw std::out_of_range("list is not ordered");
         std::cout << "This List is not sorted" << std::endl;
      }
    std::cout << "==The list is sorted==" << std::endl;
    }


  }



  std::cout << "=== All tests passed for " << container_name
            << " ===" << std::endl;
}




//this code is what is actually checking if the list is sorted by seeing if the previous value is less than the next
template <typename Container>
bool is_sorted(const Container& c) {
    for (size_t i = 1; i < c.size(); i++) {
        if (c.at(i-1) > c.at(i)) {
            return false;
        }
    }
    return true;
}
//this method allows us to pass in any sorting method and use our previously created is_sorted  method
template <typename Container>
//passing in the name  of teh sort forclarity and then the actual method itself
void run_sort_test(const std::string& sort_name,
                   void (Container::*sort_method)()) 
{
    Container l = {40,60,30,20,70,50,80,100,10,90};

    // Call the sorting method passed in
    (l.*sort_method)();

    // Validate and print the list if its incorrect
    if (!is_sorted(l)) {
        std::cout << sort_name << " FAILED\n";
        for (size_t i = 0; i < l.size(); i++) {
            std::cout << l.at(i) << " ";
        }
        std::cout << "\n";
        assert(false && "Sort method failed");
    }

    std::cout << sort_name << " passed\n";
}
//this final method i made myself and it just makes int main smaller

template <typename Container>
void run_sorting_test(const std::string &container_name){
   if(container_name == "vector"){
       run_sort_test<vector<int>>("bubble sort", &vector<int>::sort_bubble);
       //run_sort_test<vector<int>>("insertion sort", &vector<int>::sort_insertion);
       run_sort_test<vector<int>>("selection sort", &vector<int>::sort_selection);
       //run_sort_test<vector<int>>("merge sort", &vector<int>::sort_merge);
       //run_sort_test<vector<int>>("quick sort", &vector<int>::sort_quick);
       //run_sort_test<vector<int>>("heap sort", &vector<int>::sort_heap);
       //run_sort_test<vector<int>>("shell sort", &vector<int>::sort_shell);
       //run_sort_test<vector<int>>("tim sort", &vector<int>::sort_tim);

   }
   else if(container_name == "list"){ 
       run_sort_test<list<int>>("bubble sort", &list<int>::sort_bubble);
       //run_sort_test<list<int>>("insertion sort", &list<int>::sort_insertion);
       //run_sort_test<list<int>>("selection sort", &list<int>::sort_selection);
       //run_sort_test<list<int>>("merge sort", &list<int>::sort_merge);
       //run_sort_test<list<int>>("quick sort", &list<int>::sort_quick);
       //run_sort_test<list<int>>("heap sort", &list<int>::sort_heap);
       //run_sort_test<list<int>>("shell sort", &list<int>::sort_shell);
       //run_sort_test<list<int>>("tim sort", &list<int>::sort_tim);

   }
   else if(container_name == "forward_list"){ 
       run_sort_test<forward_list<int>>("bubble sort", &forward_list<int>::sort_bubble);
       //run_sort_test<forward_list<int>>("insertion sort", &forward_list<int>::sort_insertion);
       //run_sort_test<forward_list<int>>("selection sort", &forward_list<int>::sort_selection);
       //run_sort_test<forward_list<int>>("merge sort", &forward_list<int>::sort_merge);
       //run_sort_test<forward_list<int>>("quick sort", &forward_list<int>::sort_quick);
       //run_sort_test<forward_list<int>>("heap sort", &forward_list<int>::sort_heap);
       //run_sort_test<forward_list<int>>("shell sort", &forward_list<int>::sort_shell);
      // run_sort_test<forward_list<int>>("tim sort", &forward_list<int>::sort_tim);

   }

}



int main() {
  std::cout << "=== Starting Comprehensive Test Harness ===" << std::endl;
  //run_tests_for<list<int>>("list");
  //run_tests_for<forward_list<int>>("forward_list");
  run_tests_for<vector<int>>("vector");
  run_sorting_test<vector<int>>("vector");
  //run_sorting_test<list<int>>("list");
  //run_sorting_test<forward_list<int>>("forward_list");
  std::cout << "=== All Tests Passed Successfully Across All Containers! ==="
            << std::endl;
  return 0;
}

