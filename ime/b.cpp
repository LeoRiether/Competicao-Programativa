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
const ll oooo = ll(oo)*oo;

const int N = 1005;

string a, b; 
int jump[27][N];
// int dp[N][N];
ll ans[N][N];

ll dp(int i, int j) {
  if (j == -2) return -oooo;
  if (j == -1) return 0;
  // if (i == sz(a)) return 0;
  if (ans[i][j] != -1) return ans[i][j];

  if (i+1 == sz(a)) {
    if (jump[a[i]-'a'][j] == -2)
      return ans[i][j] = 0;
    else
      return ans[i][j] = 1;
  }

  return ans[i][j] = max(
    1+dp(i+1, jump[a[i]-'a'][j]),
    dp(i+1, j)
  );
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> a >> b;
  int n = sz(a), m = sz(b);
  reverse(all(b));

  memset(ans, -1, sizeof(ans));

  // Build jump map
  fo1(c, 27) {
    int l = -2;
    fo1(i, m) {
      if (b[i]-'a' == c) {
        l = i-1;
      }
      jump[c][i] = l;
    }
  }

  cout << dp(0, m-1) << endl;

  // for (int i = n-1; i >= 0; i--) {
  //   for (int j = 0; j < m; j++) {
  //     if (i+1 >= n) {
  //       dp[i][j] = 0;
  //     } else if (jump[a[i]-'a'][j] == -1) {
  //       dp[i][j] = 1+dp[i+1][j-1]
  //     } else if (jump[a[i]-'a'][j] == -2) {
  //       dp[i][j] = 0;
  //     } else {
  //       dp[i][j] = max(
  //         1+dp[i+1][jump[a[i]-'a'][j]],
  //         dp[i+1][j]
  //       );
  //     }
  //   }
  // }
  
  // cout << dp[0][m-1] << endl;

  return 0;
}