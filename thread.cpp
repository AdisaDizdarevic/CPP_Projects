#include <iostream>
#include <thread>

using namespace std;

int sharedVariable = 0;

void incrementSharedVariable() {

  for (int i = 0; i < 100000; ++i) {

    sharedVariable++;
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
