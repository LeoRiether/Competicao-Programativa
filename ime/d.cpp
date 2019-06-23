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
const ll oooo = ll(oo)*oo;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<ll> s(n<<1);
  fo1(i, n<<1) {
    cin >> s[i];
  }

  sort(all(s));

  ll mx = -1;
  ll mn = oooo;
  int i = 0, j = sz(s)-1;
  while (i < j) {
    mx = max(mx, s[i]+s[j]);
    mn = min(mn, s[i]+s[j]);
    i++; j--;
  }
  cout << mx-mn << endl;
  return 0;
}