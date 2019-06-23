#include <bits/stdc++.h>
using namespace std;

#define fo1(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
using ll = long long; using vi = vector<int>; using ii = pair<int,int>;
template <typename A, typename B> ostream& operator<<(ostream& os, pair<A,B> p) { return os << '{' << p.first << ", " << p.second << '}'; }
const int oo = 0x3f3f3f3f;

const int N = 100005;

map<string, int> names;

int p[N];
int ss[N];

void Build() {
  fo1(i, N) {
    p[i] = i;
    ss[i] = 1;
  }
}

int Find(int i) {
  while (p[i] != i)
    i = p[i] = p[p[i]];
  return i;
}

bool SameSet(int i, int j) {
  return Find(i) == Find(j);
}

void Union(int i, int j) {
  i = Find(i);
  j = Find(j);
  if (i == j) return;
  if (ss[i] < ss[j]) swap(i, j);
  p[j] = i;
  ss[i] += ss[j];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, q; cin >> n >> q;
  fo1(i, n) {
    string s; cin >> s;
    names[s] = i;
  }
  Build();

  while (q --> 0) {
    int t; cin >> t;
    string u; cin >> u;
    string v; cin >> v;
    if (t == 1) {
      Union(names[u], names[v]);
    } else {
      // cout << names[u] << ' ' << names[v] << ' ' << Find(names[u]) << ' '<< Find(names[v]) << endl;
      cout << (SameSet(names[u], names[v]) ? "yes\n" : "no\n");
    }
  }

  return 0;
}