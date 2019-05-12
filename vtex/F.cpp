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

struct Box {
  int x, y, z;
};

bool cmp(Box& a, Box& b) {
    if (a.x == b.x) {
      if (a.y == b.y)
        return a.z < b.z;
      return a.y < b.y;
    }
    return a.x < b.x;
  }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<Box> v;
  v.resize(n);
  int x,y,z;
  fo1(i, n) {
    cin >> x >> y >>z;
    v[i] = {x,y,z};
  }
  sort(all(v), cmp);

  rep(i, 0, n-1) {
    if (v[i].x >= v[i+1].x || v[i].y >= v[i+1].y || v[i].z >= v[i+1].z) {
      cout << "N\n";
      return 0;
    }
  }

  cout << "S\n";
  return 0;
}