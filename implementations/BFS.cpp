#include <iostream>
#include <vector>
#include <queue>

typedef std::vector<std::vector<size_t>> graph_t;

// Example input
// 7
// -1
// 2 5 -1
// 1 3 5 -1
// 2 4 -1
// 6 5 3 -1
// 1 2 4 -1
// 4 -1

// Reads n vertices
// Example of a vertex: 0 4 -1 => this vertex is connected to vertex 0 and 4
graph_t readGraph(int n) {
  graph_t g(n);
  int k;
  for (int i = 0; i < n; i++) {
    std::cin >> k;
    while (k != -1) {
      g[i].push_back(k);
      std::cin >> k;
    } 
  }
  return g;
}

// Returns the minimum distance between "from" and "to"
int bfs(const graph_t& g, size_t from, size_t to) {
  std::vector<bool> visited(g.size(), false); 
  std::queue<std::pair<size_t, int>> q;
  q.emplace(from, 0);
  visited[from] = true;

  std::pair<size_t, int> i;
  while (!q.empty()) {
    i = q.front(); q.pop();

    // Push every edge to the queue
    for (const auto edge : g[i.first]) {
      if (edge == to) // Found
        return i.second+1;
      if (!visited[edge]) {
        q.emplace(edge, i.second+1);
        visited[edge] = true;
      }
    }
  }

  return -1; // No such path
}

int main() {
  int n;
  std::cin >> n;
  graph_t g { readGraph(n) };

  std::cout << bfs(g, 4, 1) << std::endl;  
  
  return 0;
}