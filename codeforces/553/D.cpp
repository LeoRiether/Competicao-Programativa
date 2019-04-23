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
  int a, b;

  vector<tuple<int,int,int>> q(n);

  fo1(i, n) {
    cin >> a >> b;
    if (a >= b) {
      if (!q[0])  
        q[0] = make_tuple(i, a, b);
      else if (q[0][2]*(n-1)) {

      }
    }
    else {

    }
  }

  return 0;
}