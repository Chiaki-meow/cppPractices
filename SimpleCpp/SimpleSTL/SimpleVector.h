// Simple SLT Vector implement
// 	1.	动态数组的基本操作（增、删、查）
//	2.	支持迭代器
//	3.	支持自动扩展和收缩
// ref: Chiaki + ChatGPT

#ifndef CPPPRACTICES_SIMPLEVECTOR_H
#define CPPPRACTICES_SIMPLEVECTOR_H

#include <utility>
#include <cstddef>

template<typename T>
class SimpleVector {
private:
    T *data;
    size_t size;
    size_t capacity;
public:
    SimpleVector() : size(0), capacity(1) {
        data = new T[capacity];
    };

    ~SimpleVector() { delete[] data; };

    size_t getSize() const {
        return size;
    };

    size_t getCapacity() const {
        return capacity;
    };

    bool isEmpty() const {
        return size == 0;
    };

    void push_back(const T &value) {
        if (size == capacity) {
            size_t newCapacity = capacity * 2;
            T *newData = new T[capacity];
            for (int i=0; i<size; i++){
                newData[i] = std::move(data[i]);
            }
            // memccpy(newData, data, size, sizeof(T));

            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[size] = value;
        size++;
    };

    void pop_back() {
        if (size == 0) return;
        size--;
    };

    void clear() {
        size = 0;
    };

    // operator overloading
    T &operator[](size_t index) {
        return data[index];
    };

    const T &operator[](size_t index) const {
        return data[index];
    };
};

#endif //CPPPRACTICES_SIMPLEVECTOR_H
