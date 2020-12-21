#include <iostream>
#include <vector>

//
// TO DONE (in another segtree implementation) : Implement lazy propagation
//

// Sum Segment Tree
template <typename T>
class Segtree {
  typedef typename std::vector<T>::iterator iterator_t;

  std::vector<int> st;

  void buildSegtree(const std::vector<T>& e, size_t i, size_t l, size_t r) {
    if (l == r) {
      st[i] = e[l];
      return;
    }

    size_t mid = (l+r)>>1;
    buildSegtree(e, (i<<1)+1, l, mid);
    buildSegtree(e, (i<<1)+2, mid+1, r);
    st[i] = st[(i<<1)+1] + st[(i<<1)+2];
  }

  T query(size_t ql, size_t qr, size_t i, size_t nl, size_t nr) {
    // Query is completely contained in node range
    if (nl >= ql && nr <= qr)
      return st[i];

    // Query completely outside of node range
    if (qr < nl || ql > nr)
      return 0;

    // Query partially within node range, recurse to find answer
    size_t mid = (nl+nr)>>1;
    return query(ql, qr, (i<<1)+1, nl, mid) + query(ql, qr, (i<<1)+2, mid+1, nr);
  }

  void update() {

  }

public:
  iterator_t begin() { return st.begin(); }
  iterator_t end()   { return st.end();   }
  size_t size() { return st.size(); }
  size_t capacity() { return st.capacity(); }

  Segtree(const std::vector<T> e) {
    st.resize((e.size()<<1)-1);
    buildSegtree(e, 0, 0, e.size()-1);
  }

  T query(size_t l, size_t r) { return query(l, r, 0, 0, (st.size()-1)>>1); }
  void update(size_t i, T e) { update(); }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Segtree<T>& st) {
  int a{0};
  for (auto i : st) {
    os << (a++ ? " " : "") << i;
  }
  return os;
}

int main() {
  Segtree<int> st({ 1,2,-1,3,-6,5,-3,1 });

  std::cout << st << std::endl;
  std::cout << st.query(2, 6) << std::endl;

  return 0;
}
