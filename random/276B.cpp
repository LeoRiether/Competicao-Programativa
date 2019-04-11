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

  string s; cin >> s;

  map<char, int> count;
  for (const char c : s) {
    count[c]++;
  }

  int oddCount = 0;
  for (const auto p : count) {
    if (p.second & 1) oddCount++;
  }

  if (s.size() & 1) {
    cout << ((oddCount & 1) ? "First" : "Second");
  } else {
    cout << ((oddCount & 1) ? "Second" : "First");
  }

  return 0;
}