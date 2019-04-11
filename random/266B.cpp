#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// O(t*n) solution
// not too good
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  int t; cin >> t;

  vector<char> q(n);
  fo1(i, n) {
    cin >> q[i];
  }

  // The obscure "t slides to zero" operator
  while (t --\
              \
               \
                > 0) {
    fo1(i, n-1) {
      if (q[i] == 'B' && q[i+1] == 'G') {
        swap(q[i], q[i+1]);
        i++;
      }
    }
  }

  for (const auto a: q) {
    cout << a;
  }

  return 0;
}