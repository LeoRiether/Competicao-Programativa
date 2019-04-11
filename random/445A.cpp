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
  int m; cin >> m;

  char inp;
  fo1(i, n) {
    fo1(j, m) {
      cin >> inp;
      if (inp == '-') {
        cout << '-';
      } else {
        cout << ((((i&1)+j) & 1) == 0 ? 'B' : 'W');
      }
    }
    cout << '\n';
  }

  return 0;
}