#include <iostream>
#include "SimpleSTL/SimpleVector.h"
#include "SimpleSTL/SimpleString.h"
#include "SimpleSharedPtr.h"
#include "TestClass.h"

void vector_int_test();
void vector_test_class_test();
void shared_ptr_test_class_test();

int main() {
  vector_int_test();
  vector_test_class_test();
  shared_ptr_test_class_test();
  return 0;
}

void vector_int_test() {
  SimpleVector<int> vec;

  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);

  std::cout << "Size: " << vec.getSize() << ", Capacity: " << vec.getCapacity() << std::endl;

  for (size_t i = 0; i < vec.getSize(); ++i) {
    std::cout << "Element " << i << ": " << vec[i] << std::endl;
  }

  vec.pop_back();
  std::cout << "After pop_back, Size: " << vec.getSize() << std::endl;

  vec.clear();
  std::cout << "After clear, Size: " << vec.getSize() << std::endl;
}

void vector_test_class_test() {
  SimpleVector<TestClass> vec;
  TestClass test;
  vec.push_back(TestClass(test));
  vec.push_back(TestClass(test));
  vec.push_back(TestClass(test));

  std::cout << "Size: " << vec.getSize() << ", Capacity: " << vec.getCapacity() << std::endl;

  for (size_t i = 0; i < vec.getSize(); ++i) {
    std::cout << "Element " << i << ": " << vec[i] << std::endl;
  }

  vec.pop_back();
  std::cout << "After pop_back, Size: " << vec.getSize() << std::endl;

  vec.clear();
  std::cout << "After clear, Size: " << vec.getSize() << std::endl;

}

void shared_ptr_test_class_test() {
  SmartPtr<TestClass> ptr1(new TestClass());
  std::cout << "Use count after creating ptr1: " << ptr1.use_count() << std::endl;
  {
    SmartPtr<TestClass> ptr2 = ptr1;
    std::cout << "Use count after creating ptr2: " << ptr2.use_count() << std::endl;
    ptr2->getValue();
  }
  std::cout << "Use count after ptr2 out of scope: " << ptr1.use_count() << std::endl;
  SmartPtr<TestClass> ptr3(new TestClass());
  ptr3 = ptr1;
  std::cout << "Use count after assigning ptr3 to ptr1: " << ptr1.use_count() << std::endl;
  ptr3->getValue();
}