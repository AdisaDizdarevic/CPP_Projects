#include <iostream>
#include <sstream>
#include <stdexcept>

void sum(int a, int b = 5) { std::cout << a + b; }

void output() {
  std::ostringstream oss;
  oss << "scientific: " << std::scientific << 12.345;
  std::cout << oss.str();
}

template <typename T = std::string, typename S = std::string> T to(S arg) {
  std::stringstream i;
  T r;
  if (!(i << arg) || !(i >> r) || !(i >> std::ws).eof())
    throw std::runtime_error{"to<>() failed"};
  return r;
}

int main() {
  auto x1 = to<std::string, double>(1.2);
  auto x2 = to<std::string>(1.2);
  auto x3 = to<>(1.2);
  auto x4 = to(1.2);
  sum(5);
  sum(4, 4);

  return 0;
}
