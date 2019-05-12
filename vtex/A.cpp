#include <bits/stdc++.h>
using namespace std;

#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << endl;
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
using ll = long long; using vi = vector<int>; using ii = pair<int,int>;
const int oo = 0x3f3f3f3f;
#define ff first
#define ss second

vector<ii> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  v.reserve(2*n);
  int a, b;
  fo1(i, n) {
    cin >> a >> b;
    v.emplace_back(a, 'e');
    v.emplace_back(b, 's');
  }
  sort(all(v));

  int mn = 0;
  int inside = 0;
  int lastE = -1;
  rep(i, 0, 2*n-1) {
    if (v[i].ss == 'e') {
      inside++;
      lastE = i;
    } else {
      inside--;
    }
    if (inside > 0)
      mn = max(mn, v[i+1].ff - v[lastE].ff);
  }
  cout << mn;

  return 0;
}