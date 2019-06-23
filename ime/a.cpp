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

const int N = 2002;

int dist[N];
vector<vi> edg;

int dfs(int i, int n) {
  memset(dist, oo, sizeof(dist));
  queue<ii> q;
  q.emplace(i, 0);
  dist[i] = 0;

  int x, d;
  while (q.size()) {
    tie(x, d) = q.front(); q.pop();
    for (const auto y : edg[x]) {
      if (d+1 < dist[y]) {
        dist[y] = d+1;
        q.emplace(y, dist[y]);
      }
    }
  }

  int mx = -1;
  rep(i, 1, n+1) {
    mx = max(mx, dist[i]);
  }
  return mx;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  int m; cin >> m;
  edg.resize(n+1);
  fo1(i, m) {
    int a, b; cin >>a >> b;
    edg[a].emplace_back(b);
    edg[b].emplace_back(a);
  }

  
  int mx = -1;
  rep(i, 1, n+1) {
    mx = max(mx, dfs(i, n));
  }

  if (mx == oo) {
    cout << "=[ " << endl;
  } else {
    cout << "=] " << mx << endl;
  }
  
  return 0;
}