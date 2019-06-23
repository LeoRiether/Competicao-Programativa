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

int s[15];
int n; 
ll x, d;

bool can(int m) {
  int mn = oo;
  int mx = 0;
  ll sum = 0;
  int i = 0;
  while (m > 0) {
    if (m&1) {
      mx = max(mx, s[i]);
      mn = min(mn, s[i]);
      sum += s[i];
    }
    i++;
    m >>= 1;
  }
  return mx-mn <= d && sum >= x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> x >> d;
  const int maxM = 1<<(n);
  fo1(i, n)
    cin >> s[i];

  int t = 0;
  for (int m = 1; m < maxM; m++) {
    t += can(m);
  }
  cout << t << endl;
  return 0;
}