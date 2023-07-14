#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

struct Foo {
  Foo(std::string t, int n) : text(t), num{n} {}
  // destructor deleted

  std::string text;
  int num;
};

int main() {
  std::vector<Foo> v;

  v.push_back(Foo("foo 1", 1));
  v.push_back(Foo("foo 2", 2));
  v.push_back(Foo("foo 3", 3));

  for (auto &foo : v) {
    std::cout << "foo.text: '" << foo.text << " " << foo.num << "'\n";
  }

  Foo fooBack = std::move(v.back());

  std::cout << "fooBack.text: '" << fooBack.text << " " << fooBack.num << "'\n";

  for (auto &foo : v) {
    std::cout << "foo.text: '" << foo.text << " " << foo.num << "'\n";
  }

  return 0;
}
