#include <iostream>

template <typename T> T fun(int f, T u) { return u * f; }
template <class T> T fun2(T f, T u) { return f * u; }
int fun2(int f, int u) { return f * u; }
int main() {
  std::cout << fun(5, 3) << " " << fun2(5, 3) << std::endl;
  std::cout << fun(5, 3.5) << " " << fun2(5, 3.5) << std::endl;
  std::cout << fun(5, 'A') << " " << fun2(5, 'A') << std::endl;
  std::cout << fun(5, false) << " " << fun2(5, false) << std::endl;
  return 0;
}
