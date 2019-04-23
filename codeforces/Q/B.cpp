#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Top tier coding right here
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  int k;
  set<int> s;
  fo1(i, n) {
    cin >> k;
    s.insert(k);
  }

  vi v;
  for (const auto i : s)
    v.push_back(i);

  // Does this even work?
  if (v.size() > 3) {
    cout << -1;
  } 
  else if (v.size() == 3) {
    if (v[2] - v[1] == v[1] - v[0]) cout << v[1] - v[0];
    else cout << -1;
  } 
  else if (v.size() == 2) {
    if ((v[1]-v[0]) % 2 == 0) cout << (v[1]+v[0])/2 - v[0];
    else cout << v[1]-v[0];
  }
  else if (v.size() == 1) {
    cout << 0;
  }

  return 0;
}