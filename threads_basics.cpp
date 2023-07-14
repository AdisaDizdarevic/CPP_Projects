#include <functional>
#include <iostream>
#include <thread>
#include <vector>

struct c {

  c(const std::vector<int> &vv, int *p) : v{vv}, res{p} {}
  void operator()() {
    for (auto o : v) {
      std::cout << o;
    };
  }

private:
  const std::vector<int> &v;
  int *res;
};

void f(const std::vector<int> &v, int *res) { *res = *v.begin(); };

int g(const std::vector<int> &v) { return *v.begin(); }

int main() {

  int res1, res2, res3;

  std::vector<int> v1{1, 3, 5, 7};
  std::vector<int> v2{2, 4, 6, 8};
  std::vector<int> v3{10, 9, 8, 7};

  std::thread t1{f, std::cref(v2), &res2};
  std::thread t2{c{v1, &res1}};
  std::thread t3{[&]() { res3 = g(v3); }};

  t1.join();
  t2.join();
  t3.join();

  std::cout << res1 << " " << res2 << " " << res3;
}
