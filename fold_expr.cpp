#include <iostream>
#include <vector>

template <typename... T> int sum(T... v) { return (v + ... + 0); }

template <typename... T> void print(T &&...o) {
  (std::cout << ... << o) << std::endl;
}

template <typename V, typename... Ts> std::vector<V> to_vector(Ts &&...ts) {
  std::vector<V> v;
  (v.push_back(ts), ...);
  return v;
}

template <typename T, typename... Ts> void fct(T, Ts &&...ts) {
  auto x = to_vector<T>(ts...);
  for (auto e : x) {
    std::cout << e << std::endl;
  }
}

int main() {
  std::cout << sum(3, 4, 5, 2, 40, 'a') << std::endl;

  print("eyy", 1, "    hm", 3, 7.8);

  fct('a', 1, 2, 3, 4, 'a');
  return 0;
}
