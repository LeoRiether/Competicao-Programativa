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
  int open = 0;
  char c;
  stringstream out;
  fo1 (i, n) {
    cin >> c;
    if (c == '(') {
      open++;
      out << c;
    }
    else if (c == ')') {
      open--;
      out << c;
    }
    else {
      if (i == n-1 && open == 1) {
        open--;
        out << ')';
      } 
      else if (open >= 2) {
        open--;
        out << ')';
      } 
      else if (open == 1 || open == 0) {
        open++;
        out << '(';
      } 
    }

    if (open <= 0 && i != n-1) { cout << ":("; return 0; }
  }

  if (open == 0) {
    cout << out.str();
  } 
  else {
    cout << ":(";
  }

  return 0;
}