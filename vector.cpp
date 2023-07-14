#include <iostream>
#include <vector>
struct Entry {
  std::string name;
  int number;
};

std::ostream &operator<<(std::ostream &out, Entry e) {
  out << e.name << " " << e.number << std::endl;
  return out;
}

std::istream &operator>>(std::istream &in, Entry e) {
  in >> e.name >> e.number;
  return in;
}

//
// void print(const std::vector<Entry> &book) {
//   for (int i = 0; i != book.size(); ++i)
//     std::cout << book[i] << '\n';
// }
//
void print(const std::vector<Entry> &e) {
  for (auto el : e)
    std::cout << "Ispis: " << el << std::endl;
}

void input() {
  std::vector<Entry> el;
  Entry e;
  while (std::cin >> e) {
    el.push_back(e);
  }
  std::cin.ignore();
  std::cin.clear();

  print(el);
}

int main() {
  std::vector<Entry> phone_book = {{"David Hume", 123456},
                                   {"Karl Popper", 234567},
                                   {"Bertrand Arthur William Russell", 345678}};

  print(phone_book);
  std::vector<Entry> p1 = phone_book;
  print(p1);
  std::vector<double> v(5, 6.6);
  for (auto el : v) {
    std::cout << el << std::endl;
  }
  // input();  *Nije gotovoo..*
  return 0;
}
