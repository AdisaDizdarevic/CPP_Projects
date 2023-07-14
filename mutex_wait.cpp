#include <chrono>
#include <cmath>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex m1;

int sh = 500;
int i = 0;

void f1(int &a) {
  for (int e = 0; e < 100000; ++e) {
    std::scoped_lock l{m1};
    ++a;
  }
  auto t0 = std::chrono::high_resolution_clock::now();
  std::this_thread::sleep_for(std::chrono::milliseconds{20});
  auto t1 = std::chrono::high_resolution_clock::now();
  std::cout << (t1 - t0).count() << " ~ ";
}

void f2(int &a) {
  for (int e = 0; e < 100000; ++e) {
    std::scoped_lock l{m1};
    ++a;
  }
}

int main() {
  std::thread t1{f1, std::ref(sh)};
  std::thread t2{f2, std::ref(sh)};
  t1.join();
  t2.join();
  std::cout << i << " " << sh << std::endl;
  return 0;
}
