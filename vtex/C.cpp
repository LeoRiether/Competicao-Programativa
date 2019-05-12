#include <bits/stdc++.h>
using namespace std;

#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << endl;
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
using ll = long long; using vi = vector<int>; using ii = pair<int,int>;
const int oo = 0x3f3f3f3f;

class Matrix {
public:
  int w, h;
  vector<int> data;

  // Matrix(int w, int h) : w(w), h(h) {
  //   data.resize(w*h);
  // }

  inline void init(int w_, int h_) {
    w = w_;
    h = h_;
    data.resize(w*h);
  }

  inline void reset() {
    data.assign(w*h, 0);
  }

  // s/in/within
  inline bool inBounds(int x, int y) {
    return x >= 0 && x < w && y >= 0 && y < h;
  }

  inline int& operator()(int x, int y) {
    return data[x + y*w];
  }

  inline void operator()(int x, int y, int v) {
    data[x + y*w] = v;
  }
};

Matrix m, c, ans;

int f(int x, int y) {
  if (ans(x, y)) { return ans(x, y); }
  // c.reset();

  queue<ii> q;

  int t = 0;
  bool foundAns = false;
  while (m.inBounds(x, y) && (ans(x,y) || c(x, y) == 0)) {
    if (ans(x, y)) { t += ans(x, y); foundAns = true; break; }
    c(x, y) = 1;
    q.emplace(x, y);
    t++;
    switch(m(x, y)) {
      case 'W': x--; break;
      case 'E': x++; break;
      case 'N': y--; break;
      case 'S': y++; break;
    }
  }

  // if (foundAns) cerr << "! ";
  if (!m.inBounds(x, y) || foundAns) {
    int k = t;
    int x1, y1;
    while(!q.empty()) {
      tie(x1, y1) = q.front(); q.pop();
      ans(x1, y1, k--);
    }
  }
  else {
    int k = t;
    int x1 = -1, y1 = -1;
    while(!q.empty()) {
      tie(x1, y1) = q.front();
      if (x1 == x && y1 == y) break;
      q.pop();
      ans(x1, y1, k--);
    }
    while (!q.empty()) {
      tie(x1, y1) = q.front(); q.pop();
      ans(x1, y1, k);
    }
  }
  return t;  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int w, h; cin >> h >> w;
  m.init(w, h);
  c.init(w, h);
  ans.init(w, h);
  char character;
  fo1(i, h) {
    fo1(j, w) {
      cin >> character;
      m(j, i) = int(character);
    }
  }

  // fo1(i, h){
  //   fo1(j, w) {
  //     cerr << char(m(j,i)) << ' ';
  //   }
  //   cerr << endl;
  // }

  ll sum = 0;
  fo1(i, h) {
    fo1(j, w) {
      if (!ans(j,i)) f(j, i);
      sum += ans(j, i);
      // cerr << j<<", " << i << " : " << ans(j,i) << endl;
    }
  }
  cout << sum;

  return 0;
}