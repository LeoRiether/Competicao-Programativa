#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll gcd(ll a, ll b) {
  ll aux;
  while (b > 0) {
    aux = b;
    b = a % b;
    a = aux;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  ll n; cin >> n;
  ll m; cin >> m;

  cout << "YES\n";
  while (n < m) {
    cout << n << ' ' << n+1 << '\n';
    n += 2;
  }

  return 0;
}