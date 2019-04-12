#include <iostream>
#include <ctime>
#include <random>

int main() {
  std::string hw {"Hello World Hello World Hello World Hello World "};

  std::cout << '!';
  for (auto it = hw.begin(); it != hw.end(); it++) {
    char c = '!';
    if (*it == ' ') {
      std::cout << ' ';
    } 
    else {
      while (c != *it) {
        c = rand() % (255 - 0) + 0;
        // c = rand() % ('z' - 'A') + 'A';
        std::cout << '\b' << c;
        for (int i = 0; i < 100000; i++);
      }
      std::cout << ' ';
    }
  }

  std::cout << "!\n";

  
  return 0;
}