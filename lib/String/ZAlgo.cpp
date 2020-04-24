#include <bits/stdc++.h>
using namespace std;

//
//  ACTUALLY BETTER THAN KMP
//

using vi = vector<int>;

vi Z_handbook(string s) {
  int n = s.size();
  vi z(n);
  int x = 0, y = 0;
  for (int i = 1; i < n; i++) {
    z[i] = max(0, min(z[i - x], y - i + 1));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      x = i; y = i + z[i]; z[i]++;
    }
  }
  return z;
}

int main() {
  string S, P;
  cout << "String: "; cin >> S;
  cout << "Pattern: "; cin >> P;
  string PS = P + '#' + S;

  cout << endl << "Z function for pattern:" << endl;
  for (int i = 0; i < (int)P.size(); i++)
    cout << setw(2) << i << ' ';
  cout << endl;
  for (const char c : P)
    cout << ' ' << c << ' ';
  cout << endl;
  
  vi z = Z(P);
  for (const int i : z)
    cout << setw(2) << i << ' ';
  cout << endl;


  cout << endl << "Z function for pattern+string:" << endl;
  for (int i = 0; i < (int)PS.size(); i++)
    cout << setw(2) << i << ' ';
  cout << endl;
  for (const char c : PS)
    cout << ' ' << c << ' ';
  cout << endl;
  
  z = Z(PS);
  for (const int i : z)
    cout << setw(2) << i << ' ';
  cout << endl;

  cout << endl << "Matches found at positions: ";
  for (int i = 0; i < (int)z.size(); i++) {
    if (z[i] == (int)P.size()) {
      cout << i << ' ';
    }
  }
  cout << endl;
}
