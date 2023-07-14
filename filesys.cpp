#include <filesystem>
#include <iostream>

using namespace std::filesystem;
void print_dir(path p) {
  if (is_directory(p)) {
    std::cout << p << std::endl;
    for (const directory_entry &x : directory_iterator{p})
      std::cout << " " << x.path() << std::endl;
  }
}

int main() {
  print_dir(".");
  print_dir("..");
  print_dir("/");
  return 0;
}
