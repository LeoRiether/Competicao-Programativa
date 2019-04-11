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

  int n; cin >> n;
  vi flowers(n);
  fo1(i, n) {
    cin >> flowers[i];
  }
  sort(flowers.begin(), flowers.end());

  int ans = flowers.back() - flowers.front();
  if (ans == 0) {
    ll q = static_cast<ll>(n);
    cout << "0 " << (q*(q-1))/2;
    return 0;
  }
  ll ti{0}, tj{0};
  int i{0}, j{static_cast<int>(flowers.size())-1};
  while (i < j && flowers[i++] == flowers.front()) ti++;
  while (j > 0 && flowers[j--] == flowers.back())  tj++;

  cout << ans << ' ' << ti*tj;

  return 0;
}