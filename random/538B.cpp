#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// TODO: better variable naming
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  if (n == 1e6) { cout << "1\n1000000"; return 0; }
  int k = n;

  // There's so much useless code here
  // Please don't look too much at it

  vector<int> c(6,0);
  int q = 0;
  while (n) {
    c[q++] = n % 10;
    n /= 10;
  }

  vector<int> r;
  while (k) {
    int p10 = 1;
    int ans = 0;
    fo1(i, 6) {
      if (c[i]) {
        ans += p10;
        c[i]--;
      }
      p10 *= 10;
    }
    k -= ans;
    r.pb(ans);
  }

  cout << r.size() << '\n';
  for (const int a : r) {
    cout << a << ' ';
  }

  return 0;
}