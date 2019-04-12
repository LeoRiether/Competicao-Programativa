#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> cost, path;
vector<int> tb;
int n;

ll minCost(int i) {
  if (tb[i]) return tb[i];

  
}

ll minCost() {
  ll ans = minCost(0);
  for (int i = 1; i < n; i++) {
    ans = min(ans, minCost(i));
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n;
  cost.resize(n); path.resize(n); tb.resize(n,0);
  fo1 (i, n) cin >> cost[i];
  fo1 (i, n) cin >> path[i];

  cout << minCost();

  return 0;
}