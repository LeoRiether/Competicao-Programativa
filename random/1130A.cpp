#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Really??
// Is this it?
// I must be missing something
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  int pos {0}, neg {0};
  int k;
  fo1(i, n) {
    cin >> k;
    if (k > 0) pos++;
    else if (k < 0) neg++;
  }

  if (pos >= ceil(n/2.0)) {
    cout << 1;
  } else if (neg >= ceil(n/2.0)) {
    cout << -1;
  } else {
    cout << 0;
  }

  return 0;
}