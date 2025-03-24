#include <initializer_list>
#include <iostream>
#include <string>

#include "SimpleSTL/SimpleString.h"
#include "SimpleSTL/SimpleVector.h"
#include "SimpleSharedPtr.h"
#include "TestClass.h"

void vector_int_test();
void vector_test_class_test();
void shared_ptr_test_class_test();
void initializer_list_test();

int main() {
  vector_int_test();
  vector_test_class_test();
  shared_ptr_test_class_test();
  initializer_list_test();
  return 0;
}

void vector_int_test() {
  SimpleVector<int> vec;

  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);

  std::cout << "Size: " << vec.getSize() << ", Capacity: " << vec.getCapacity()
            << std::endl;

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

  std::cout << "Size: " << vec.getSize() << ", Capacity: " << vec.getCapacity()
            << std::endl;

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
  std::cout << "Use count after creating ptr1: " << ptr1.use_count()
            << std::endl;
  {
    SmartPtr<TestClass> ptr2 = ptr1;
    std::cout << "Use count after creating ptr2: " << ptr2.use_count()
              << std::endl;
    ptr2->getValue();
  }
  std::cout << "Use count after ptr2 out of scope: " << ptr1.use_count()
            << std::endl;
  SmartPtr<TestClass> ptr3(new TestClass());
  ptr3 = ptr1;
  std::cout << "Use count after assigning ptr3 to ptr1: " << ptr1.use_count()
            << std::endl;
  ptr3->getValue();
}

class Widget {
public:
  Widget(int i, bool b) { std::cout << "Constructor (int, bool)" << std::endl; }
  Widget(int i, double d) {
    std::cout << "Constructor (int, double)" << std::endl;
  }
  Widget(std::initializer_list<long double> il) {
    std::cout << "Constructor (initializer_list<long double>)" << std::endl;
  }
  Widget(const Widget &other) { std::cout << "Constructor Copy" << std::endl; }
  // 有内部的string类型转换：会调用拷贝构造函数
  // operator std::string() const { std::cout<< "Constructor String" <<
  // std::endl; return "Widget_String"; }
  operator float() const {
    std::cout << "Constructor Float" << std::endl;
    return 0.0;
  }
};

void initializer_list_test() {
  Widget w1(10, true);   // OK
  Widget w2(5, 3.14);    // OK
  Widget w3{1.0L, 2.0L}; // OK: 调用 initializer_list<long double>

  Widget w4 = w1; // OK: 调用拷贝构造（隐式）
  Widget w6{w4};
}
