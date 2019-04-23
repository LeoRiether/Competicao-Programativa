#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<bool> s;
int n,b,a; 

ll hashIt(int t0, int t1, int t2, int t3) {
  return static_cast<ll>(t0) << 15LL | static_cast<ll>(t1) << 30LL | static_cast<ll>(t2) << 45LL | t3;
}

// vector<int> ans; // how?
map<ll, int> ans;// like this?

int dfs(int i, int ta, int tb, int opt) {
  auto p = hashIt(i,ta,tb,opt); // q lindo
  if (ans[p]) return ans[p];
  if (i == n) return i;
  if (opt == 1 && i != 0 && s[i-1] && ta < a) ta++;
  int distA = ta <= 0 ? i : dfs(i+1, ta-1, tb, 0);
  int distB = tb <= 0 ? i : dfs(i+1, ta, tb-1, 1);
  ans[p] = max(distA, distB);
  return max(distA, distB);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n>>b>>a;

  s.resize(n);
  int aux;
  fo1(i ,n) {
    cin >> aux;
    s[i] = aux == 1;
  }

  cout << dfs(0, a, b, -1);

  return 0;
}