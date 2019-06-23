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

vector<string> ans;

class Trie {
public:
  char c;
  bool marker;
  vector<Trie> v;

  void insert(string& s, int i) {
    if (i == sz(s)) {
      if (marker) {
        ans.emplace_back(s);
      }
      marker = true;
      return;
    }
    for (auto& t : v) {
      if (t.c == s[i]) {
        t.insert(s, i+1);
        return;        
      }
    }
    v.emplace_back(Trie{ s[i], false });
    v.back().insert(s, i+1);
  }
};

struct Root {
  vector<Trie> v;

  void insert(string& s) {
    for (auto& t : v) {
      if (t.c == s[0]) {
        t.insert(s, 1);
        return;
      }
    }
    v.emplace_back(Trie{ s[0], false });
    v.back().insert(s, 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  Root rt;
  string s;
  fo1(i, n) {
    cin >> s;
    if (sz(s) < 4) continue;
    rt.insert(s);
  }

  if (sz(ans)) {
    cout << sz(ans) << '\n';
    for (const auto& ss : ans)
      cout << ss << '\n';
  } else {
    cout << "SAFO\n";
  }

  return 0;
}