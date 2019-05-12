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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, k; cin >> n >> k;
  vector<pair<int, char>> time(n+1);
  vector<pair<int, ii>> customers;
  customers.reserve(n);
  int c1, c2;
  fo1(i, n) {
    cin >> c1 >> c2;
    customers.push_back({c1, {c2, i+1}});
  }
  sort(all(customers));

  queue<ii> A, B;
  for(const auto c : customers) {
    while (!A.empty() && A.front().ss >= c.ff) A.pop();
    while (!B.empty() && B.front().ss >= c.ff) B.pop();
    if (sz(A) == 0) {
      A.emplace(c.ss.ss, c.ff + c.ss.ff);
      time[c.ss.ss] = { A.back().ss, 'A' };
    } else if (sz(A) <= sz(B)) {
      A.emplace(c.ss.ss, max(A.back().ss, c.ff) + c.ss.ff);
      time[c.ss.ss] = { A.back().ss, 'A' };
    } else if (sz(B) == 0) {
      B.emplace(c.ss.ss, c.ff + c.ss.ff*k);
      time[c.ss.ss] = { B.back().ss, 'B' };
    } else {
      B.emplace(c.ss.ss, max(B.back().ss, c.ff) + c.ss.ff*k);
      time[c.ss.ss] = { B.back().ss, 'B' };
    }
  }

  rep(i, 1, n+1) {
    cout << time[i].ss << ' ' << time[i].ff << '\n';
  } 

  return 0;
}