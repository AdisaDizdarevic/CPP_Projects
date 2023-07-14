#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <vector>

int main() {
  std::vector<int> v;
  v.emplace_back(1);
  v.emplace_back(2);
  v.push_back(3);
  v.emplace_back(8);
  v.emplace_back(0);
  std::sort(v.begin(), v.end(), [](int l, int r) { return l > r; });
  for (auto e : v) {
    std::cout << e << std::endl;
  }

  std::list<int> l;
  l.emplace_back(1);
  l.emplace_back(2);
  l.emplace_back(4);
  l.emplace_back(6);
  l.emplace_back(7);
  l.emplace_back(1);
  l.pop_front();
  l.sort([](int l, int r) { return l > r; });
  for (auto e : l) {
    std::cout << e << " ";
  }

  std::map<std::string, int> m;
  m.insert({"adisa", 19149});
  m.insert({"adis", 1234});
  m.insert({"adi", 1111});
  m.insert({"ad", 100});
  m["a"] = 10;
  m.emplace("haz", 1234);
  for (auto e : m) {
    std::cout << e.first << " " << e.second << " ";
  }
  std::cout << m.find("a")->second;
  return 0;
}
