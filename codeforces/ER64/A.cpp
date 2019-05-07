#include <bits/stdc++.h>
using namespace std;

#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << endl;
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
#define SORT(x) sort((x).begin(), (x).end())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int k; cin >> k;
  vi v(k);
  fo1(i, k) cin >> v[i];

  int p = 0;
  int n;
  bool inf = false;
  for (int i = 0; i < k-1 && !inf; i++) {
    n = v[i+1];
    if (v[i] == 1) {
      if (n==2) {
        p += 3;
      } else {
        p += 4;
      }
    } else if (v[i] == 2) {
      if (n==1) {
        p += 3;
      } else {
        inf = true;        
      }
    } else if (v[i] == 3) {
      if (n==1) {
        p += 4;
        if (i+2 < k && v[i+2] == 2) p--;
      } else if (n==2) {
        inf = true;
      }
    }
  }

  cout << (inf ? "Infinite\n" : "Finite\n");
  if (!inf) {
    cout << p;
  }

  return 0;
}