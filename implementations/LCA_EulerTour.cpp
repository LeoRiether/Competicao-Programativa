#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100005; // MaxN = 100005 runs out of stack space :(
const int MaxLog = 18;

vector<vector<int>> adj;
vector<pair<int, int>> et; // Euler tour array
int F[2*MaxN]; // first ocurrence of node i

void eulerDfs(int n, int p, int depth) {
  if (!F[n]) F[n] = et.size();
  et.emplace_back(depth, n);
  for (const auto e : adj[n]) {
    if (e == p) continue;
    eulerDfs(e, n, depth+1);
    et.emplace_back(depth, n);
  }
}

int logt[MaxN];
pair<int,int> st[MaxN][MaxLog];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  // Read tree
  int n; cin >> n;
  adj.resize(n+1);
  for (int i = 0; i < n-1; i++) {
    int a, b; cin >> a >> b;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  // Construct euler tour (assuming 1 as root)
  et.reserve(2*n);
  eulerDfs(1, 0, 0);

  // Preprocess logs
  logt[1] = 0;
  for (int i = 2; i < MaxN; i++)
    logt[i] = logt[i/2] + 1;

  // Build sparse table
  memset(st, 0, sizeof(st));
  for (int i = 0; i < int(et.size()); i++)
    st[i][0] = et[i];
  for (int k = 1; k < MaxLog; k++) {
    for (int i = 0; i < int(et.size()); i++) {
      if (i + (1<<(k-1)) < int(et.size()))
        st[i][k] = min(st[i][k-1], st[i + (1<<(k-1))][k-1]);
      else
        st[i][k] = st[i][k-1];
    }
  }

  int x, y;
  int l, r;
  while (cin >> x >> y) {
    if (x < 0 || y < 0) break;
    l = F[x]; r = F[y];
    int k = logt[r-l+1];
    cout << "LCA(" << x << ", " << y << ") = ";
    cout << min(st[l][k], st[r - (1<<k) +1][k]).second << endl;
  }

  return 0;
}