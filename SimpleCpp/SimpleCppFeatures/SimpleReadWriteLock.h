//
// Created by Chiaki_meow on 2025/2/17.
//

#ifndef CPPPRACTICES_SIMPLEREADWRITELOCK_H
#define CPPPRACTICES_SIMPLEREADWRITELOCK_H

#include <condition_variable>
#include <mutex>

class ReadWriteLock {
private:
  std::mutex mtx;
  std::condition_variable cv;
  unsigned int readers = 0;
  bool writer = false;
  unsigned int waiting_writers = 0;

public:
  ReadWriteLock() = default;
  ~ReadWriteLock() = default;

  ReadWriteLock(const ReadWriteLock &other) = delete;
  ReadWriteLock &operator=(const ReadWriteLock &other) = delete;
  ReadWriteLock(ReadWriteLock &&other) = delete;
  ReadWriteLock &operator=(ReadWriteLock &&other) = delete;

  void read_lock() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this] { return !writer && waiting_writers == 0; });
    ++readers;
  }

  void read_unlock() {
    std::unique_lock<std::mutex> lock(mtx);
    --readers;
    if (readers == 0) {
      cv.notify_all();
    }
  }

  void write_lock() {
    std::unique_lock<std::mutex> lock(mtx);
    ++waiting_writers;
    cv.wait(lock, [this] { return !writer && readers == 0; });
    --waiting_writers;
    writer = true;
  }

  void write_unlock() {
    std::unique_lock<std::mutex> lock(mtx);
    writer = false;
    cv.notify_all();
  }

  bool try_read_lock() {
    std::unique_lock<std::mutex> lock(mtx);
    if (writer || waiting_writers > 0)
      return false;
    readers++;
    return true;
  }

  bool try_write_lock() {
    std::unique_lock<std::mutex> lock(mtx);
    if (writer || readers > 0)
      return false;
    writer = true;
    return true;
  }
};

#endif // CPPPRACTICES_SIMPLEREADWRITELOCK_H
