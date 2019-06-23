#include <bits/stdc++.h>
using namespace std;

#define fo1(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
using ll = long long; using vi = vector<int>; using ii = pair<int,int>;
template <typename A, typename B> ostream& operator<<(ostream& os, pair<A,B> p) { return os << '{' << p.first << ", " << p.second << '}'; }
const int oo = 0x3f3f3f3f;

const int N = 100001;
// using fn_t = int(*)(int, int);
typedef int (*fn_t)(int, int);

int dosum(int a, int b){
  return a+b;
}

int domax(int a, int b) { return max(a, b); }
int domin(int a, int b) { return min(a, b); }

struct ST {
  vi t;
  int n;
  int en;
  fn_t f;

  ST(int i, int n, int en) : n(n), en(en) {
    if (i == 0) f = &dosum;
    if (i == 1) f = &domax;
    if (i == 2) f = &domin;
    t.resize(2*n);
  }

  void build() {
    for (int i = n-1; i > 0; i--)
      t[i] = f(t[i<<1], t[i<<1|1]);
  }

  int query(int l, int r) {
    if (l == r-1) return t[l+n];

    int ans = en;
    for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
      if (l&1) ans = f(ans, t[l++]);
      if (r&1) ans = f(ans, t[--r]);
    }
    return ans;
  }

  void update(int i, int x) {
    for (t[i+=n] = x; i > 1; i>>=1)
      t[i>>1] = f(t[i], t[i^1]);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, q; cin >> n >> q;
  ST s (0, n, 0);
  ST mx(1, n, -1);
  ST mn(2, n, oo);
  fo1(i, n) {
    int x; cin >> x;
    s.t[i+n] = x;
    mx.t[i+n] = x;
    mn.t[i+n] = x;
  }

  s.build();
  mn.build();
  mx.build();

  while (q --> 0) {
    int k; cin >> k;
    if (k == 1) {
      int l, r; cin >> l >> r;
      l--;
      // cout << 0 << ' ' << l << ' ' << r << endl;
      // cout << 1 << ' ' << s.query(l, r) << endl;
      // cout << 2 << ' ' << mx.query(l, r) << endl;
      // cout << 3 << ' ' << mn.query(l, r) << endl;
      cout << s.query(l, r) - mx.query(l, r) - mn.query(l, r) << '\n';
    } else {
      int i, v; cin >> i >> v;
      i--;
      s.update(i, v);
      mn.update(i, v);
      mx.update(i, v);
    }
  }

  return 0;
}