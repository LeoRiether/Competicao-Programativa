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

  int n, aux; cin >> n;
  int a[n];
  fo1(i, n) {
    cin >> aux;
    a[aux-1] = i;
  }
  int b, q; cin >> b;
  ll fromLeft{0}, fromRight{0};
  while (b --> 0) {
    cin >> q;
    aux = a[q-1];
    fromLeft += aux+1;
    fromRight += n-aux;
  }

  cout << fromLeft << ' ' << fromRight;

  return 0;
}