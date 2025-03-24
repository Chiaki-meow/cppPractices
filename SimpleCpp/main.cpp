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
void enable_shared_from_this_test();

int main() {
  // vector_int_test();
  // vector_test_class_test();
  // shared_ptr_test_class_test();
  // initializer_list_test();
  enable_shared_from_this_test();
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


class Widget : public std::enable_shared_from_this<Widget> {
public:
  Widget() { std::cout << "Default constructor" << std::endl; };

  // 测试initializer_list的用法
  Widget(int i, bool b) { std::cout << "Constructor (int, bool)" << std::endl; }
  Widget(int i, double d) {
    std::cout << "Constructor (int, double)" << std::endl;
  }
  Widget(std::initializer_list<long double> il) {
    std::cout << "Constructor (initializer_list<long double>)" << std::endl;
  }
  Widget(const Widget &other) { std::cout << "Constructor Copy" << std::endl; }
  // 有内部的string类型转换：会调用拷贝构造函数，不会用string重载
  // operator std::string() const { std::cout<< "Constructor String" <<
  // std::endl; return "Widget_String"; }

  // 有内部的float类型转换
  operator float() const {
    std::cout << "Constructor Float" << std::endl;
    return 0.0;
  }

  // 测试 enable_shared_from_this 的作用
  std::shared_ptr<Widget> getSharedPtr() {
    // return std::shared_ptr<Widget>(this);  // 错误❌ 会使得返回一个和本体的shared_ptr相独立的shared_ptr
    return shared_from_this();  // ✅ 正确获取已有 shared_ptr
  }

  
  ~Widget() { std::cout << "Widget destroyed\n"; }
};

void initializer_list_test() {
  Widget w1(10, true);   // OK
  Widget w2(5, 3.14);    // OK
  Widget w3{1.0L, 2.0L}; // OK: 调用 initializer_list<long double>

  Widget w4 = w1; // OK: 调用拷贝构造（隐式）
  Widget w6{w4};
}

void enable_shared_from_this_test() {
  Widget widget;
  std::shared_ptr<Widget> p1 = std::make_shared<Widget>();
  std::shared_ptr<Widget> p2 = p1->getSharedPtr();

  std::cout << "Use count: " << p1.use_count() << std::endl;
}