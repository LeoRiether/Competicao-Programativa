#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi op;
vector<vi> c;
int in, ax;

int dfs(int i, int q) {
  if (c[i].empty()) 
    return (q == 1 ? ax-- : in++);

  int ans = (op[i] == 1 ? -1 : 0x3f3f3f3f);
  for (const auto n : c[i]) {
    ans = op[i] == 1 ? max(ans, dfs(n, op[i])) : min(ans, dfs(n, op[i]));
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  op.resize(n);
  fo1(i, n) cin >> op[i];

  // Create a children vector, not a parent vector
  c.resize(n);
  int aux;
  fo1(i, n-1) {
    cin >> aux;
    c[aux-1].emplace_back(i+1);
  }

  // Count leaf nodes
  int k = 0;
  for (const auto cc : c) {
    if (cc.empty()) k++;
  }

  in = 1;
  ax = k;
  cout << dfs(0, 1);

  return 0;
}