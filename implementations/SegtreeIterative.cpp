#include <bits/stdc++.h>
using namespace std;

// Simple segtree with point update and range queries
struct Seg0 {
  vector<int> t;
  int n;
  Seg0(int n) : n(n) {
    t.resize(2*n+1);
  }

  void build() {
    for (int i = n-1; i > 0; i--)
      t[i] = t[i<<1] + t[i<<1|1];
  }

  void update(int i, int x) {
    for(i+=n; i > 0; i>>=1)
      t[i] += x;
  }

  // Sums [l, r)
  int query(int l, int r) {
    int ans = 0;
    for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
      if (l&1) ans += t[l++];
      if (r&1) ans += t[--r];
    }
    return ans;
  }
};

int main() {
  int n; cin >> n;
  Seg0 a(n);
  for(int i = 0; i < n; i++)
    cin >> a.t[n+i];
  a.build();

  int q; cin >> q;
  while (q --> 0) {
    char type; cin >> type;
    if (type == 'u') { // update
      int i, x; cin >> i >> x;
      a.update(i, x);      
    } else if (type == 'q') { // query
      int l, r; cin >> l >> r;
      cout << a.query(l, r) << endl;
    }
  }

  return 0;
}