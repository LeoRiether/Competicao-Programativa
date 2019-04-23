#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, t; cin >> n >> t;
  ll t0, r0;
  ll m = {0x3f3f3f3f};
  ll k;
  int idx = 1;
  fo1 (i, n) {
    cin >> t0 >> r0;
    k = t0 >= t ? t0 : ((t-t0+r0-1)/r0) * r0 + t0;
    if (k < m) {
      m = k;
      idx = i+1;
    }
  }

  cout << idx;

  return 0;
}