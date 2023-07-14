#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T> using Iterator = typename T::iterator;
// T’s iterator
template <typename C, typename V>
std::vector<Iterator<C>> find_all(C &c, V v)
// find all occurrences of v in c
{
  std::vector<Iterator<C>> res;
  for (auto p = c.begin(); p != c.end(); ++p)
    if (*p == v)
      res.push_back(p);
  return res;
}
int main() {
  std::string m{"Mary had a little lamb"};
  auto a = find_all(m, 'a');
  for (auto p : a) {
    if (*p != 'a')
      std::cerr << "string bug!\n";
    std::cout << *p;
  }
  std::list<double> ld{1.1, 2.2, 3.3, 1.1};
  auto l = find_all(ld, 1.1);
  for (auto p : l) {
    if (*p != 1.1)
      std::cerr << "list bug!\n";
    std::cout << *p;
  }
  // p is a string::iterator
  // p is a list<double>::iterator
  std::vector<std::string> vs{"red",   "blue",   "green",
                              "green", "orange", "green"};
  auto r = find_all(vs, "red");
  for (auto p : r) {
    // p is a vector<string>::iterator
    if (*p != "rad")
      std::cerr << "vector bug!\n";
    std::cout << *p;
  }

  for (auto p : find_all(vs, "green"))
    *p = "vert";
}
