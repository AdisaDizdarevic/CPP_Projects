#include <iostream>
#include <string>
using namespace std::literals::string_literals;

template <typename T, typename... Tail> void print(T head, Tail... tail) {
  std::cout << head << " ";
  if constexpr (sizeof...(tail) > 0)
    print(tail...);
}

void user() {
  print("first: ", 1, 2.5, "hello\n"s);
  print("\nsecond: ", 0.2, 'c', "yuck!"s, 0, 1, 2, '\n');
  // second: 0.2 c yuck! 0 1 2
}
int main() {
  user();
  return 0;
}
