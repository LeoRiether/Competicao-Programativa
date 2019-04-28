#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
#define SORT(x) sort((x).begin(), (x).end())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

inline bool inverseSign(int a, int b) {
  return (a >> 31) ^ (b >> 31);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  if(n == 1) { cout << "yes\n1 1"; return 0; } // Don't want to deal with this

  vi v(n);
  fo1(i, n) cin >> v[i];

  // Make sure there's at most one reversal
  int ndelta, delta = v[1] - v[0];
  int reversals = 0, ridx = n, ridx2 = n;
  fo1(i, n-1) {
    ndelta = v[i+1] - v[i];
    if (inverseSign(delta, ndelta)) {
      reversals++;
      ridx = ridx2;
      ridx2 = i+1;
    }
    delta = ndelta;
  }

  if (reversals == 0) {
    // Either sorted backwards or forwards
    if (v[n-1]-v[0] >= 0) cout << "yes\n 1 1";
    else cout << "yes\n1 " << n;
  }
  else if (reversals == 1) {
    // Either sorted backwards + sorted forwards or the opposite
    
  }
  else if (reversals == 2) {
    // Either sorted forwards + backwards + forwards or you can't sort it
    
  }
  else {
    cout << "no"; // TODO: find a counterexample
  }



  return 0;
}