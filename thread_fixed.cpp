#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

mutex m;

int sharedVariable = 0;

void incrementSharedVariable() {

  for (int i = 0; i < 100000; ++i) {
    unique_lock lck{m};
    sharedVariable++;
    lck.unlock();
  }
}

int main() {
  std::thread t1(incrementSharedVariable);
  std::thread t2(incrementSharedVariable);
  std::thread t3(incrementSharedVariable);

  t1.join();
  t2.join();
  t3.join();

  std::cout << sharedVariable << endl;
  return 0;
}
