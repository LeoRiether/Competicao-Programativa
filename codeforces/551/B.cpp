#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// prediction: this will fail on test 3

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n,m,h; cin >> n>>m>>h;
  vi front(m);
  vi left(n);
  fo1(i,m) cin >> front[i];
  fo1(i,n) cin >> left[i];

  int k;
  fo1(i, n) {
    fo1(j, m) {
      cin >> k;
      if (k) {
        if (front[j] <= left[i] && front[j] != -1) { 
          k = front[j]; 
          // front[j] = -1;
        } else if (left[i] <= front[j] && left[i] != -1) {
          k = left[i];
          // left[i] = -1;
        } else {
          k = front[j]; // what the fuck am I doing
        }
      }
      cout << k << ' ';
    }
    cout << '\n';
  }

  return 0;
}