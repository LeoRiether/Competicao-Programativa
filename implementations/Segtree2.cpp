#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

using vi = vector<int>;

#define LEFT(i) 2*i+1
#define RIGHT(i) 2*i+2

int getSTSize(int x) {
  return 1<<int(ceil(log2(x))+1);
}

struct Segtree {
  int n;
  vi data, lazy;

  Segtree(int n) : n(n) {
    int s = getSTSize(n);
    data.resize(s,0);
    lazy.resize(s,0);
  }

  int query(int l, int r, int i, int nl, int nr) {
    if (nr < l || nl > r)
      return 0;
    
    if (nl >= l && nr <= r) {
      return data[i] + lazy[i]*(nr-nl+1);
    }

    int mid = (nl+nr)/2;
    lazy[LEFT(i)] += lazy[i];
    lazy[RIGHT(i)] += lazy[i];
    lazy[i] = 0;
    return query(l, r, LEFT(i), nl, mid) +
           query(l, r, RIGHT(i), mid+1, nr);
  }

  int query(int l, int r) {
    return query(l, r, 0, 0, n-1);
  }

  void update(int l, int r, int i, int nl, int nr, int delta) {
    if (nr < l || nl > r)
      return;

    if (nl >= l && nr <= r) {
      lazy[i] += delta;
      return;
    }

    data[i] += delta*(r-l+1);

    int mid = (nl+nr)/2;
    update(l, r, LEFT(i), nl, mid, delta);
    update(l, r, RIGHT(i), mid+1, nr, delta);
  }

  void update(int l, int r, int delta) {
    update(l, r, 0, 0, n-1, delta);
  }

};

int main() {
  int n; cin >> n;

  Segtree st(n);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    st.update(i, i, x);
  }

  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    char t; cin >> t;
    if (t == 'U') {
      int l, r, x; cin >> l >> r >> x;
      st.update(l, r, x);
    } else if (t == 'Q') {
      int l, r; cin >> l >> r;
      cout << st.query(l, r) << endl;
    } else {
      cout << "Tipo da query não foi reconhecido" << endl;
    }
  }

  return 0;
}