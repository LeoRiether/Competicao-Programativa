#include <iostream>
#include <queue>
#include <vector> 
#include <tuple>

typedef std::vector<std::vector<std::pair<int,int>>> adj_list_t;

// Min-heap
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

  // Read all edges
  int from, to, weight;
  for (int i = 0; i < e; i++) {
    std::cin >> from >> to >> weight;
    adj[from].emplace_back(weight, to);
    adj[to].emplace_back(weight, from);
  }

  std::cout << prim(adj, v, 1) << std::endl;

  return 0;
}