#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string s; cin >> s;
  stringstream d;

  int i = 0, n = s.size();
  while (i < n) {
    if (s[i] == '.') {
      d << '0';
      i++;
    }
    else if (s[i] == '-') {
      // Assuming a valid string
      d << ((s[++i] == '.') ? '1' : '2');
      i++;
    } else {
      d << "~Hello World!~"; 
      i<<=i;
    }
  }

  cout << d.str();

  return 0;
}