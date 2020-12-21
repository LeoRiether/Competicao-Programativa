#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

constexpr int N = 10005; // only 10^4 so my compiler doesn't run out of stack memory and makes me look for segmentation fault for half an hour

// 
// Inspired by: https://codeforces.com/blog/entry/58025
//

vector<vi> g; // edges on main tree
vector<vi> G; // edges on centroid tree
bitset<N> seen;
bitset<N> erased;
int ts[N]; // (sub)tree size

// Returns the size of subtree rooted at u
// u - current node
// p - parent of u
int dfs_sz(int u, int p) {
  ts[u] = 1;
  for (const auto v : g[u]) if (v != p && !erased[v]) {
    ts[u] += dfs_sz(v, u);
  }
  return ts[u];
}

// Finds the centroid of the subtree rooted at u
int findCentroid(int u) {
  int n = dfs_sz(u, -1);

  // Returns the centroid
  function<int (int, int)> dfs = [&](int u, int p) {
    for (const auto v : g[u]) if (v != p && !erased[v]) {
      if (ts[v] > n/2)
        return dfs(v, u); // move on the direction of the centroid
    }
    return u; // found the centroid
  };

  return dfs(u, -1);
}

// Decomposes the subtree rooted at u
// p - parent on the centroid tree (var G)
int decompose(int u, int p) {
  u = findCentroid(u);
  erased[u] = true;
  if (p != -1)
    G[p].emplace_back(u);
  for (const auto v : g[u]) if (!erased[v]) {
    decompose(v, u);
  }
  
  return u;
}

int main() {
  int n; cin >> n;
  g.resize(n);
  G.resize(n);

  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  int root = decompose(0, -1);
  cout << root << endl;

  return 0;
}