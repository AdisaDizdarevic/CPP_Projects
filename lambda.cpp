#include <iostream>

int main() {

  int a = 10, b = 10;

  auto l = [&a, b]() mutable {
    b = 15;
    return ++a + b;
  };

  std::cout << a << " " << b << std::endl;
  std::cout << l() << std::endl;
  std::cout << a << " " << b << std::endl;
}
