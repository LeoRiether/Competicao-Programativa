#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

template <typename T>
class Map {
private:
  T* data;

public:
  int w, h;

  Map(int w, int h) : w(w), h(h) {
    data = new T[w*h];
  }

  T& operator()(int i, int j) {
    return data[i*w + j];
  }
};

template <>
class Map<bool> {
private:
  std::vector<char> data;

public:
  int w, h;

  Map(int w, int h) : w(w), h(h) {
    data.resize((w*h+7)/8);
  }

  bool operator()(int i, int j) {
    int idx = i*w+j;
    return data[idx/8] & (1<<(idx%8));
  }

  void operator()(int i, int j, bool v) {
    int idx = i*w+j;
    if (v) {
      data[idx/8] = data[idx/8] | (1<<(idx%8));
    } else {
      data[idx/8] = data[idx/8] & ~(1<<(idx%8));
    }
  }
};

std::vector<int> dx { 1,-1,0,0 };
std::vector<int> dy { 0,0,1,-1 };

template <typename T>
inline int floodfillPoint(Map<T>& map, Map<bool>& visited, int iStart, int jStart) {
  std::queue<std::pair<int,int>> q;
  q.emplace(iStart, jStart);

  int i, j;
  int vcount = 0;
  while (!q.empty()) {
    std::tie(i, j) = q.front(); q.pop();
    visited(i, j, true);
    vcount++;
    for (int t = 0; t < 4; t++) {
      int y = i + dy[t], x = j + dx[t];
      if (map(y, x) == '$' && !visited(y, x)) {
        q.emplace(y, x);
      }
    }
  }
  return vcount;
}

// Returns the number of pools of '$'
// Also might be O(n^2)
template <typename T>
std::pair<int,int> floodfill(Map<T>& map) {
  Map<bool> visited(map.w, map.h);

  int pools = 0, poolCount = 0;
  for (int i = 0; i < map.h; i++) for (int j = 0; j < map.w; j++) {
    if (map(i, j) == '$' && !visited(i, j)) {
      poolCount += floodfillPoint(map, visited, i, j);
      pools++;
    }
  }
  return {pools, poolCount};
}

void query() {
  int w, h;
  std::cin >> w >> h;

  Map<char> map(w, h);

  for(int i = 0; i < w; i++) {
    for(int j = 0; j < h; j++) {
      std::cin >> map(i, j);
    }
  }

  int pools, poolCount;
  std::tie(pools, poolCount) = floodfill(map);

  std::cout << pools << ' ' << poolCount << std::endl;
}

int main() {
  int q;
  std::cin >> q; // Q queries
  while(q--) query();

  return 0;
}