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

  // Wouldn't need this if k was the second parameter
  vi a(n);
  {
    int i0;
    fo1(i, n) {
      cin >> i0; cin >> a[i];
    }
  }

  int k; cin >> k;
  int m{0};
  fo1(i, n) {
    if (k <= a[i]) m++;
  }
  cout << m;

  return 0;
}