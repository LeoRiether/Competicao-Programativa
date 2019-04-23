#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string gen = "ACTG";

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;

  string s; cin >> s;
  int ans = 0x3f3f3f3f;
  // O(4n), it's fine
  fo1(i, n-3) {
    int c = 0;
    fo1(j, 4) {
      // c += min(abs(s[i+j] - gen[j]), abs('Z'+1 + gen[j] - s[i+j] - 'A'));
      int k = abs(s[i+j] - gen[j]);
      if (k > 13) k = abs(k-26);
      c += k;
    }
    ans = min(ans, c);
  }

  cout << ans;

  return 0;
}