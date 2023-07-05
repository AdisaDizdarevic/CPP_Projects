#include <chrono>
#include <iostream>
#include <iterator>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;
mutex m;
void print1(const std::vector<int> &v) {
  unique_lock l{m};
  for (auto e : v) {
    std::cout << e << "  ";
    this_thread::sleep_for(chrono::milliseconds{150});
  }
};

void print2(std::vector<int> &v) {
  unique_lock l{m};
  for (auto it = v.begin(); it != v.end(); ++it)
    v.erase(it);
};

int main() {

  std::vector<int> v;
  for (int i = 0; i < 1000; ++i) {
    v.push_back(i);
  }

  std::thread t1{print1, ref(v)};
  std::thread t2{print2, ref(v)};

  t1.join();
  t2.join();

  return 0;
}
