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

// ????
int find(int n, int m) {
  if (!(n&1) && !(m&1)) return -1;
  int e = 1;
  for (int x = n; x <= 1000000; x *= n, e++) {
    if ((x-1)%m == 0) {
      return e;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  // int p = 3;
  // int k = 5;
  // cout << k%p << endl << endl;
  // for (int x = 1; x < 10000000; x *= p) {
  //   cout << x << ' ' << (x-1)%k << endl;
  // }

  int q; cin >> q;
  while (q --> 0) {
    int n, m; cin >> n >> m;
    // cout << 0 << '\n'; // Tecnicamente está correto!
    cout << find(n, m) << '\n';
  }
  return 0;
}