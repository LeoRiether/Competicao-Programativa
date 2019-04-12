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

  int a1,a2,a3; cin >> a1 >> a2 >> a3;
  int a = a1+a2+a3;
  int b1,b2,b3; cin >> b1 >> b2 >> b3;
  int b = b1+b2+b3;

  int n; cin >> n;

  int shelves = 0;
  shelves += ceil(a / 5.0);
  shelves += ceil(b / 10.0);

  cout << (shelves <= n ? "YES" : "NO");

  return 0;
}