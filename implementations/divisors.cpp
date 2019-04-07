#include <iostream>
#include <vector>
#include <iterator>

// Just so I can cout a vector
template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  int a{0};
  for (const auto& e : v) {
    os << (a++ ? " " : "") << e;
  }
  return os;
}

// O(sqrt(n))
std::vector<int> getDivisors(int n) {
  std::vector<int> front, back;
  for (int i = 1; i*i <= n; i++) {
    if (n % i == 0) {
      int j = n/i;
      front.push_back(i);
      if (i != j) back.push_back(j);
    }
  }
  std::move(back.rbegin(), back.rend(), std::back_inserter(front));
  return front;
}

// O(n*log n)
std::vector<int> countMultiplesTill(int n) {
  std::vector<int> divCount(n, 1);
  for (int i = 2; i < n; i++) {
    for (int d = i; d < n; d += i) {
      divCount[d]++;
    }
  }
  return divCount;
}

// O (n*log(log n))
std::vector<int> sieve(int n) {
  std::vector<int> primes;
  std::vector<bool> marked(n, false);
  for (int i = 2; i < n; i++) {
    if (!marked[i]) {
      primes.push_back(i);
      for (int j = i+i; j < n; j += i) marked[j] = true;
    }
  }
  return primes;
}

// O(n*log(log n))
std::vector<int> maxFactorTable(int n) {
  std::vector<int> f(n, 0);
  for (int i {2}; i < n; i++) {
    if (f[i] == 0)
      for (int j = i; j < n; j += i) f[j] = i;
  }
  return f;
}

// O(log n) with a maxFactorTable
std::vector<int> factorize(int n, const std::vector<int>& mft) {
  if (static_cast<int>(mft.size()) <= n) return {-1};
  std::vector<int> f;
  while (mft[n]) {
    f.push_back(mft[n]);
    n /= mft[n];
  }
  return f;
}

int main() {
  std::cout << getDivisors(10) << std::endl;
  std::cout << getDivisors(12) << std::endl;
  std::cout << getDivisors(16) << std::endl;
  std::cout << getDivisors(7727) << std::endl;
  std::cout << std::endl;

  std::cout << countMultiplesTill(50) << std::endl;
  std::cout << std::endl;

  std::cout << sieve(100) << std::endl;
  std::cout << std::endl;

  std::vector<int> mft {maxFactorTable(50)};
  std::cout << mft << std::endl;
  std::cout << std::endl;

  std::cout << factorize(32, mft) << std::endl;
  std::cout << factorize(42, mft) << std::endl;
  std::cout << factorize(47, mft) << std::endl;
  std::cout << std::endl;

  return 0;
}