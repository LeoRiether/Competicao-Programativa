#include <bits/stdc++.h>

// 
// ~~Copied~~ Inspired by: https://github.com/joseleite19/icpc-notebook/blob/master/code/ed/hld.cpp
// Best implementation of HLD I've seen.
// It's pretty damn clever
//

const int N = 10005;
// A lot of memory
int ts[N]; // (sub)tree size
int in[N], out[N], id[N], nxt[N]; // id and out are not necessary in some cases
int P[N]; // Parent pointers
int dfsTime;

int dfs_sz(int u, int p) {
  ts[u] = 1;
  P[u] = p;

  // Removes parent pointer (for no apparent reason? probably has a reason)
  for (auto& v : g[u]) if (v == p) {
    swap(v, g[u].back());
    g[u].pop_back();
    break;
  }

  for (auto& v : g[u]) {
    ts[u] += dfs(v, u);
    // g[u][0] always has the heavy edge
    if (ts[v] > ts[g[u][0]])
      swap(v, g[u][0]);
  }

  return ts[u];
}

// set nxt[root] = root beforehand
// [ in[nxt[u]], in[u] ] is the path from nxt[u] to u
// [ in[u], out[u] ) is the subtree of u
void hld(int u) {
  in[u] = dfsTime++;
  id[in[u]] = u;
  for (const auto v : g[u]) {
    nxt[v] = (v == g[u][0] ? nxt[u] : v);
    hld(v);
  }
  out[u] = dfsTime;
}

// Aplies an operation on the path from u to v
// ~~Also copied~~ Heavily inspired by https://codeforces.com/blog/entry/22072
void processPath(int u, int v, function<void (int, int)>& op) {
  for (; nxt[u] != nxt[v]; v = P[nxt[v]]) {
    if (in[nxt[u]] > in[nxt[v]]) swap(u, v);
    op(in[nxt[v]], in[v]+1);
  }
  if (in[u] > in[v]) swap(u, v);
  op(in[u]+1, in[v]+1); // excludes P[lca] modification
}

int main() {
  // Nope, not going to test this now
  return 0;
}