#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

bool isSorted(std::vector<int>::iterator from, std::vector<int>::iterator to) {
  for (from++; from != to; from++) {
    if (*(from-1) > *from) return false;
  }
  return true;
}

// Runs surprisingly fast for a possible O(infinity) algorithm
void bogosort(std::vector<int>::iterator from, std::vector<int>::iterator to) {
  while (!isSorted(from, to)) {
    std::random_shuffle(from, to);
  }
}

int main() {
  std::vector<int> a { 2,1,3,6,7,4,5 };

  std::srand(time(NULL));
  bogosort(a.begin(), a.end());

  for (const auto i : a) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;

  return 0;
}