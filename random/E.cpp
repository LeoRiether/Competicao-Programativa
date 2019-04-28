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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  int q; cin >> q;
  vi ans(n,0);
  int b;
  fo1(i, q) {
    cin >> b;
    ans[(b-1)%n]++;
  }

  for (const auto i : ans) {
    cout << i << ' ' ;
  }
  

  return 0;
}