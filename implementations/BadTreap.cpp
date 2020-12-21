#include <iostream>
#include <memory>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <tuple>
#include <set>

//
// TODO: an actually good implementation
// FIXED! Know I actually know how to implement treaps
//        and this isn't the way for sure!
//

// Another TODO: Search doesn't work
// I hate shared pointers

int max(int a, int b) {
  return a > b ? a : b;
}

struct Node {
  int value;
  int rank;

  Node(int v, int r) : value(v), rank(r) { }
  Node(int v) : value(v) { rank = rand(); }
  Node() : value(0), rank(0) {}
};

// meh
#define pTreap std::shared_ptr<Treap>
using std::make_shared;

class Treap {
private:
  pTreap left, right;

  static pTreap rotateRight(pTreap t) {
    pTreap x = t->left;
    t->left = x->right;
    x->right = t;
    t->depth = max(t->left ? t->left->depth : 0, t->right ? t->right->depth : 0) + 1;
    return x;
  }

  static pTreap rotateLeft(pTreap t) {
    pTreap x = t->right;
    t->right = x->left;
    x->left = t;
    t->depth = max(t->left ? t->left->depth : 0, t->right ? t->right->depth : 0) + 1;
    return x;
  }

public:
  int depth;
  Node node;

  Treap(Node& n) : node(n) { }
  Treap(Node&& n) : node(std::move(n)) {
    n = {};
  }
  Treap() { }

  Treap* Search(int v) {
    auto t = this;
    for (;;) {
      if (!t) return nullptr;

      if (v == t->node.value)
        return t;
      if (v < t->node.value)
        t = t->left.get();
      if (v > t->node.value)
        t = t->right.get();
    }
  }

  static pTreap Insert(pTreap& t, Node& n)  {
    if (!t) {
      t = make_shared<Treap>(n);
      t->depth = 1;
      return t;
    }

    if (n.value < t->node.value) {
      t->left = Treap::Insert(t->left, n);

      if (t->left->node.rank > t->node.rank)
        t = Treap::rotateRight(t);
    } else if (n.value > t->node.value) {
      t->right = Treap::Insert(t->right, n);

      if (t->right->node.rank > t->node.rank)
        t = Treap::rotateLeft(t);
    }
    t->depth = max(t->left ? t->left->depth : 0, t->right ? t->right->depth : 0) + 1;
    return t;
  }

  static pTreap Insert(pTreap& t, Node&& n) {
    return Treap::Insert(t, n);
  }

  void InorderPrint() {
    if (left) left->InorderPrint();
    std::cout << node.value << ' ';
    if (right) right->InorderPrint();
  }

  void TreePrint() {
    std::queue<std::pair<Treap*, int>> q;
    q.emplace(this, 0);
    int lastD = 0;
    Treap* t; int d;
    while (!q.empty()) {
      std::tie(t, d) = q.front(); q.pop();
      if (d != lastD)
        std::cout << std::endl;
      lastD = d;

      if (!t) {
        std::cout << ". ";
      } else {
        std::cout << t->node.value << ' ';
        q.emplace(t->left.get(), d+1);
        q.emplace(t->right.get(), d+1);
      }
    }
  }
};

int main() {
  srand(time(NULL));

  pTreap t;
  for (int i = 0; i < 100; i++)
    Treap::Insert(t, { i });

  // t->InorderPrint();
  t->TreePrint();
  std::cout << std::endl;

  std::cout << "Treap height: " << t->depth << std::endl;

  int x;
  std::cout << "Query: ";
  while (std::cin >> x) {
    Treap* q = t->Search(x);
    std::cout << "Node value: " << q->node.value << ". Rank: " << q->node.rank << ". Depth: " << q->depth << std::endl;
    std::cout << "Query: ";
    std::cin >> x;
  }

  return 0;
}