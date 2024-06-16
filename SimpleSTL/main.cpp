#include <iostream>
#include "SimpleVector.h"

int main() {
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

    return 0;
}