#include <bits/stdc++.h>
using namespace std;

#define fo1(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, k; cin >> n >> k;
  vi h(n);
  int s = 0;
  fo1(i, n) {
    cin >> h[i];    
    if (i < k) s += h[i];
  }

  int m = s;
  int idx = 0;
  for (int i = 1; i <= n-k; i++) {
    s += h[i+k-1] - h[i-1];
    if (s < m) {
      idx = i;
      m = s;
    }
  }

  cout << idx+1;

  return 0;
}