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
};

#endif //CPPPRACTICES_TESTCLASS_H
