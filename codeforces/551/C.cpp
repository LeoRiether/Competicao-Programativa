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
  string s; cin >> s;
  
  int open = 0;
  for (int i = 0; i < n-1; i++) {
    if (s[i] == '?') {
      s[i] = (i+1 <= n/2) ? '(' : ')';
    }

    open += s[i] == '(' ? 1 : -1;
    if (open <= 0) { cout << ":("; return 0; }
  }

  s[n-1] = s[n-1] == '?' ? ')' : s[n-1];
  open += s[n-1] == '(' ? 1 : -1;

  if (open != 0) {
    cout << ":(";
  }
  else {
    cout << s;
  }

  return 0;
}