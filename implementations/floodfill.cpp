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

  T& operator()(int x, int y) {
    int idx = y*w + x;
    return data[idx];
  }

  bool withinBounds(int x, int y) {
    return x >= 0 && x < w && y >= 0 && y < h;    
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

  bool operator()(int x, int y) {
    int idx = y*w+x;
    return data[idx/8] & (1<<(idx%8));
  }

  void operator()(int x, int y, bool v) {
    int idx = y*w+x;
    if (v) {
      data[idx/8] |= (1<<(idx%8));
    } else {
      data[idx/8] &= ~(1<<(idx%8));
    }
  }

  bool withinBounds(int x, int y) {
    return x >= 0 && x < w && y >= 0 && y < h;
  }
};

std::vector<int> dx { 1,-1,0,0 };
std::vector<int> dy { 0,0,1,-1 };

template <typename T>
inline int floodfillPoint(Map<T>& map, Map<bool>& visited, int xStart, int yStart) {
  std::queue<std::pair<int,int>> q;
  q.emplace(xStart, yStart);
  visited(xStart, yStart, true);

  int x, y;
  int vcount = 0;
  while (!q.empty()) {
    std::tie(x, y) = q.front(); q.pop();
    vcount++;
    for (int t = 0; t < 4; t++) {
      int x_ = x + dx[t], y_ = y + dy[t];
      if (map.withinBounds(x_, y_) && map(x_, y_) == '$' && !visited(x_, y_)) {
        visited(x_, y_, true);
        q.emplace(x_, y_);
      }
    }
  }
  return vcount;
}

// Returns the number of pools of '$'
// Also might be O(n^4), but maybe not
template <typename T>
std::pair<int,int> floodfill(Map<T>& map) {
  Map<bool> visited(map.w, map.h);

  int pools = 0, poolCount = 0;
  for (int i = 0; i < map.h; i++) for (int j = 0; j < map.w; j++) {
    if (map(j, i) == '$' && !visited(j, i)) {
      poolCount += floodfillPoint(map, visited, j, i);
      pools++;
    }
  }
  return {pools, poolCount};
}

void query() {
  int w, h;
  std::cin >> w >> h;

  Map<char> map(w, h);

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      std::cin >> map(j, i);
    }
  }

  auto [pools, poolCount] = floodfill(map);

  std::cout << pools << ' ' << poolCount << std::endl;
}

int main() {
  int q;
  std::cin >> q; // Q queries
  while(q--) query();

  return 0;
}