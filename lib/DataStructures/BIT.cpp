#include <iostream>

#include <vector>
using namespace std;

// Least Significant Bit
#define LSB(x) ((x) & (-(x)))

// Implementação de uma Binary Indexed Tree aka Fenwick Tree
// sum() e set() são executadas em O(log n)
// Os índices começam em 1!! (tanto dos dados quanto da árvore)
template <typename T>
class BIT {
  vector<T> tree;

public:
  BIT(size_t s) { tree.resize(s, 0); }

  // Inicializa a arvore a partir de um vetor em O(nlog n)
  void init(const vector<T>& v) {
    for(size_t i = 1; i < v.size(); i++)
      update(i, v[i]);
  }

  // Retorna a soma de [1,i]
  T sum(int i) {
    T ans = 0;
    while (i > 0) {
      ans += tree[i];
      i -= LSB(i); // up, left
    }
    return ans;
  }

  // Retorna a soma de [i,j]
  T sum(int i, int j) { return sum(j) - sum(i-1); }

  // Soma delta a um elemento da lista
  void update(int i, T delta) {
    int n = static_cast<int>(tree.size());
    while (i < n) {
      tree[i] += delta;
      i += LSB(i); // up, right
    }
  }
};

int main() {
  vector<int> v { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
  BIT<int> bit(v.size());
  bit.init(v);

  cout << bit.sum(1, 3) << endl;
  cout << bit.sum(1, 10) << endl;
  cout << bit.sum(5, 9) << endl;
  cout << bit.sum(1,8) << endl << endl;

  bit.update(6, 10);
  bit.update(10, 100);

  cout << bit.sum(1, 3) << endl;
  cout << bit.sum(1, 10) << endl;
  cout << bit.sum(5, 9) << endl;
  cout << bit.sum(1,8) << endl;

}
