#include <iostream>
#include <string>

using namespace std::literals::string_literals;

template <typename T> class Less_than {
  const T val;

public:
  Less_than(const T &v) : val{v} { std::cout << "constructor" << std::endl; };
  bool operator()(const T &x) const { return x < val; }
};

int main() {
  Less_than i{42};
  // Less_than<std::string> s{"string" a};
  Less_than<std::string> s2{"string"};
  return 0;
}
