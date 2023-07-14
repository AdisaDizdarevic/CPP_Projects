#include <iostream>
#include <string>
#include <string_view>
#include <type_traits>

using namespace std::string_literals;
using namespace std::string_view_literals;

std::string add(std::string in) { return in + "++"; }

std::string add2(std::string in) {
  in += "++";
  return in;
}

std::string cat(std::string_view s1, std::string_view s2) {
  std::string res(s1.length() + s2.length(), ' ');
  char *p = &res[0];
  for (char c : s1)
    *p++ = c;
  std::copy(s2.begin(), s2.end(), p);
  return res;
}

int main() {

  std::string s = "counter", n = " ";
  std::cout << add(s) << std::endl;
  std::cout << add2(s) << std::endl;
  std::string a = s.substr(0, 5);
  std::cout << a << std::endl;
  s.replace(0, 5, "integ");
  std::cout << s << std::endl;
  n[0] = toupper(s[0]);
  std::cout << n << std::endl;
  if (s == "Integer")
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
  auto f = "something"s;
  std::cout << std::is_same<decltype(f), std::string>::value;
  std::string x = "Dizdarevic";
  auto s1 = cat(x, "Adisa");
  auto s2 = cat(x, x);
  auto s3 = cat("", "Adis"sv);
  auto s4 = cat("Amir"sv, x);
  auto s5 = cat({&x[0], 2}, "Armin"sv);
  auto s6 = cat({&x[0], 2}, {&x[2], 4});
  std::cout << " " << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5
            << " " << s6 << " " << std::endl;
  return 0;
}
