#include <bits/stdc++.h>
using namespace std;

//
//  ACTUALLY BETTER THAN KMP
//

using vi = vector<int>;

// Each element a_i of the Z-array is the length of the 
// longest prefix of P starting at i
vi Z_legacy(string P) {
  vi z(P.size());
  int l = 0, r = 0;
  int size = P.size();
  for (int i = 1; i < size; i++) {
    if (i + z[i-l] < r) {
      z[i] = z[i-l];
    } else {
      while (i + z[i] < size && P[i+z[i]] == P[z[i]])
        z[i]++;
      l = i;
      r = i+z[i];
    }
  }
  return z;
}

vi Z(string P) {
  int n = P.size();
  vi z(n);
  int x = 0, y = 0;
  for (int i = 1; i < n; i++) {
    z[i] = i+z[i-x] < y ? z[i-x] : 0;
    while (i+z[i] < n && P[z[i]] == P[i+z[i]]) {
      x = i; y = i+z[i]; z[i]++; // y = i + z[x = i]++;
    }
  }
  return z;
}

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
