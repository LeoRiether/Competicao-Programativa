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

  int n; cin >> n;
  vi a(n);
  fo1(i, n) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int j = n-1;
  int ans = 0;
  fo2(i, n-2) {
    if (a[j] > a[i]) {
      ans++;
      j--;
    }
  }

  cout << ans;

  return 0;
}