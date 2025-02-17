//
// Created by Chiaki_meow on 2025/1/8.
// Test Class 是用来测试各类STL的可靠性的。
//

#ifndef CPPPRACTICES_TESTCLASS_H
#define CPPPRACTICES_TESTCLASS_H

class TestClass {
    int value;
public:
    TestClass() : value(0) {
        std::cout<<"Default."<<std::endl;
    }

    // 拷贝构造函数
    TestClass(const TestClass &other) {
        std::cout << "Copy." << std::endl;
        this->value = other.value;
    }

    // 移动构造函数
    TestClass(TestClass &&other) noexcept {
        std::cout << "Move." << std::endl;
        this->value = other.value;
    }

    // 拷贝赋值运算符
    TestClass &operator=(const TestClass &other){
        if(this != &other){
            std::cout<<"Copy Assignment."<<std::endl;
            this->value = other.value;
        }
        return *this;
    }

    // 移动赋值运算符
    TestClass &operator=(TestClass &&other) noexcept {
        if(this != &other){
            std::cout<<"Move Assignment." <<std::endl;
            this->value = other.value;
            other.value = 0;
        }
        return *this;
    }

    int getValue() const {
        return value;
    }

};

#endif //CPPPRACTICES_TESTCLASS_H
