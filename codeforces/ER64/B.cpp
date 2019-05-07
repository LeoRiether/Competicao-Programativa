#include <bits/stdc++.h>
using namespace std;

#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << endl;
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool valid(char a, char b) {
  return abs(a - b) != 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int k; cin >> k;
  while (k--) {
    string s; cin >> s;
    vector<string> v(2);
    for (const char c : s) {
      v[(c-'a') % 2].push_back(c);
    }
    sort(all(v[0]));
    sort(all(v[1]));
    if (v[0].empty()) {
      cout << v[1];
    } else if (v[1].empty()) {
      cout << v[0];
    } else if (valid(v[0][0], v[1][0])) {
      reverse(all(v[0]));
      cout << v[0] << v[1];
    } else if (valid(v[0][0], v[1].back())) {
      cout << v[1] << v[0];
    } else if (valid(v[0].back(), v[1][0])) {
      cout << v[0] << v[1];
    } else if (valid(v[0].back(), v[1].back())) {
      reverse(all(v[1]));
      cout << v[0] << v[1];
    } else {
      cout << "No answer";
    }

    cout << '\n';
  }

  return 0;
}