#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

constexpr int oo = 0x3f3f3f3f;

using adj_list_t = std::vector<std::vector<std::pair<int,int>>>;
using dijkstra_queue_t = std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>>;

// Also works, but the time complexity is higher
// At least that is what I was told
// using dijkstra_queue_t = std::queue<std::pair<int,int>>;
// #define top front

int dijkstra(const adj_list_t& adj, int v, int from, int to) {
  dijkstra_queue_t q;
  std::vector<int> dist(v+1, oo);
  dist[from] = 0;
  q.emplace(0, from);

  int d, n;
  while (!q.empty()) {
    std::tie(d, n) = q.top(); q.pop();
    if (dist[n] < d) continue;

    // Process every edge
    for (const auto e : adj[n]) {
      // If we can improve the distance, we will
      if (dist[e.second] > dist[n] + e.first) {
        dist[e.second] = dist[n] + e.first; 
        q.emplace(dist[e.second], e.second);
      }
    }
  }

  return dist[to];
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

  std::cout << dijkstra(adj, v, 1, 9) << std::endl;

  return 0;
}
