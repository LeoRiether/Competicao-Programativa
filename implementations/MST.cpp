#include <iostream>
#include <queue>
#include <vector> 
#include <tuple>
#include <algorithm>

struct Edge {
  int from, to, weight;

  bool operator<(const Edge& x) { return weight < x.weight; }
  bool operator>(const Edge& x) { return weight > x.weight; }
};


typedef std::vector<std::vector<std::pair<int,int>>> adj_list_t;
typedef std::vector<Edge> edge_list_t;

class UnionFind {
private:
  std::vector<int> parent;
  std::vector<int> size;

public:
  UnionFind(int n) {
    parent.resize(n+1); size.resize(n+1);
    for(int i = 0; i <= n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  // Uses path halving
  int Find(int i) {
    while (parent[i] != i) {
      i = parent[i] = parent[parent[i]];
    }
    return i;
  }

  bool SameSet(int i, int j) {
    return Find(i) == Find(j);
  }

  // Union by size, so it's easier to stop Kruskal's 
  // before every edge has been processed
  void Union(int i, int j) {
    i = Find(i);
    j = Find(j);
    if (size[j] > size[i]) {
      i ^= j ^= i ^= j; // swap(i, j)
    }

    parent[j] = i;
    size[j] += size[i];
  }

  int SetSize(int i) {
    return size[Find(i)];
  }
};

int kruskal(edge_list_t& edg, int v) {
  std::sort(edg.begin(), edg.end());
  UnionFind vset(v);

  int w = 0;
  for (const Edge& e : edg) {
    if (vset.SetSize(e.from) == v) break;
    if (!vset.SameSet(e.from, e.to)) {
      w += e.weight;
      vset.Union(e.from, e.to);
    }
  }
  return w;
}

// Min-heap of pair<weight, node>
typedef std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> priority_queue_t;

int prim(const adj_list_t& adj, int v, int i) {
  // Create taken vertices list
  std::vector<bool> taken(v+1, false);

  priority_queue_t pq;
  pq.emplace(0, i);

  int mstW = 0;
  int w, n;
  while (!pq.empty()) {
    std::tie(w, n) = pq.top(); pq.pop();
    if (taken[n]) continue;
    mstW += w;
    taken[n] = true;
    for (const auto e : adj[n]) {
      if (!taken[e.second])
        pq.push(e);
    }
  }
  return mstW;
}

int main() {
  // Read number of vertices and number of edges
  int v, e;
  std::cin >> v >> e;
  adj_list_t adj(v+1);
  edge_list_t edg(e);

  // Read all edges
  int from, to, weight;
  for (int i = 0; i < e; i++) {
    std::cin >> from >> to >> weight;
    adj[from].emplace_back(weight, to);
    adj[to].emplace_back(weight, from);
    edg[i] = Edge{from, to, weight};
  }

  std::cout << kruskal(edg, v) << std::endl;
  std::cout << prim(adj, v, 1) << std::endl;

  return 0;
}