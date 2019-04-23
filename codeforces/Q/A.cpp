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

  vi t(4);
  cin >> t[0] >> t[1]>> t[2]>> t[3];
  sort(t.begin(), t.end());
  
  int a, b, c;
  c = (t[2]+t[1]-t[0])/2;
  b = c + t[0] - t[1];
  a = t[0] - b;

  cout << a << ' ' << b << ' ' << c;

  return 0;
}