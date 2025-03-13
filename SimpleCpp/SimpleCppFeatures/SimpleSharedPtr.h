//
// Created by Chiaki_meow on 2025/1/8.
//

#ifndef CPPPRACTICES_SIMPLESHAREDPTR_H
#define CPPPRACTICES_SIMPLESHAREDPTR_H

#include <cassert>

template <typename T> class SmartPtr {
  T *_ptr;
  size_t *_count;

public:
  SmartPtr(T *ptr = nullptr) : _ptr(ptr) {
    if (_ptr) {
      _count = new size_t(1);
    } else {
      _count = new size_t(0);
    }
  }

  ~SmartPtr() {
    (*this->_count)--;
    if (*this->_count == 0) {
      if (this->_ptr) {
        delete this->_ptr;
        delete this->_count;
      }
    }
  }

  SmartPtr(const SmartPtr<T> &other) {
    if (this != &other) {
      this->_ptr = other._ptr;
      this->_count = other._count;
      (*this->_count)++;
    }
  }

  SmartPtr(SmartPtr<T> &&other) noexcept {
    this->_ptr = other._ptr;
    this->_count = other._count;
    other._ptr = nullptr;
    other._count = nullptr;
  }

  SmartPtr &operator=(const SmartPtr<T> &other) {
    if (this->_ptr == other._ptr)
      return *this;
    if (this->_ptr) { // 如果存在原先的ptr，他的对应数值应-1
      (*this->_count)--;
      if (*this->_count == 0) {
        delete this->_ptr;
        delete this->_count;
      }
    }
    this->_ptr = other._ptr;
    this->_count = other._count;
    (*this->_count)++;
    return *this;
  }

  T &operator*() {
    assert(this->_ptr != nullptr);
    return *(this->_ptr);
  }

  T *operator->() {
    assert(this->_ptr != nullptr);
    return this->_ptr;
  }

  size_t use_count() { return *this->_count; }
};

#endif // CPPPRACTICES_SIMPLESHAREDPTR_H
