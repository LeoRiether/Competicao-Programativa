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

  // int a[5][5]; // There's no fucking reason to even have this array
  int k;
  int x, y;
  for (int i = 0; i < 5; i++) {
    for (int j= 0; j < 5; j++) {
      cin >> k;
      if (k == 1) {
        x=j;
        y=i;
        break; // Also this is pretty useful
      }
    }
  }

  cout << abs(x-2) + abs(y-2);

  return 0;
}