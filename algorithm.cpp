#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <ostream>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>
struct Entry {
  std::string ime;
  int index;
};

bool operator==(const Entry &x, const Entry &y) {
  return x.ime == y.ime && x.index == y.index;
};

bool operator<(const Entry &x, const Entry &y) {
  return x.ime == y.ime ? x.index < y.index : x.ime < y.ime;
}

void f(const std::vector<Entry> &vec, std::list<Entry> &lst) {
  lst.clear();

  for (const auto &e : vec) {
    lst.push_back(e);
  }
  // std::copy(vec.begin(), vec.end(), std::back_inserter(lst));
}
void f2(std::vector<Entry> &vec, std::list<Entry> &lst) {
  std::sort(vec.begin(), vec.end());
  for (auto i = vec.end() - 1; i >= vec.begin(); --i) {
    lst.push_front(std::move(*i));
    vec.pop_back();
  }
  // for (auto e : vec) {
  //   lst.push_back(std::move(e));
  // }
}

void f3(std::vector<Entry> &vec, std::list<Entry> &lst) {
  std::sort(vec.begin(), vec.end());
  // for (auto i = vec.end() - 1; i >= vec.begin(); --i) {
  // lst.push_back(std::move(*i));
  // vec.pop_back();
  // }
  for (auto e : vec) {
    lst.push_back(std::move(e));
  }
  vec.clear();
}

void find_e(std::vector<Entry> &v, const Entry &e) {
  auto it = std::find(v.begin(), v.end(), e);

  if (it != v.end())
    it->ime = "Adis";
}

int main() {
  std::vector<Entry> e = {{"Adisaa", 123456},
                          {"Ahmed", 234567},
                          {"Mirza", 345678},
                          {"Adisa", 123456}};
  std::list<Entry> l;
  // f3(e, l);
  // e[3].ime = "Muhamed";
  for (const auto &x : e)
    std::cout << x.ime << ", " << x.index << std::endl;
  // std::cout << e.size() << "  Lista: ";
  // for (const auto &x : l)
  //   std::cout << x.ime << " " << x.index << std::endl;
  find_e(e, {"Adis", 123456});

  std::cout << std::endl;
  for (const auto &x : e)
    std::cout << x.ime << ", " << x.index << std::endl;
  return 0;
}
