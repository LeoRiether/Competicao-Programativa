#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<bool> cats;
vector<bool> visited;
vector<vi> v;
ll MAX_CATS;

ll paths(int i, ll cc) {
  visited[i] = true;
  if (cats[i]) cc++;
  else cc = 0;
  if (cc > MAX_CATS) return 0;
  bool lastNode = true;
  ll p = 0;
  for (const auto edge : v[i]) {
    if (!visited[edge]) {
      lastNode = false;
      p += paths(edge, cc);
    }
  }
  return lastNode ? 1 : p;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  cin >> MAX_CATS;

  cats.resize(n);
  int a, b;
  fo1(i, n) {
    cin >> a;
    cats[i] = a == 1;
  }

  v.resize(n);
  visited.resize(n, false);
  fo1 (i, n-1) {
    cin >> a >> b;
    // if (a > b) a ^= b ^= a ^= b; // ????
    v[a-1].push_back(b-1);
    v[b-1].push_back(a-1);
  }

  cout << paths(0,0);

  return 0;
}