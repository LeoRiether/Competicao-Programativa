#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string p = "FRCFCRF";

int startAt(int i, int f, int r, int c) {
  int k[3] { f/3, r/2, c/2 };
  int m = min(k[0], min(k[1], k[2]));
  f -= m*3;
  r -= m*2;
  c -= m*2;
  int v = 0;
  while (f >= 0 && r >= 0 && c >= 0) {
    char something = p[(i+v)%7];
    if (something == 'F') {
      f--;
      if (f < 0) break;
    }
    if (something == 'R') {
      r--;
      if (r < 0) break;
    }
    if (something == 'C') {
      c--;
      if (c < 0) break;
    }
    v++;
  }
  return v+7*m;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int f, r, c; cin >> f >> r >> c;

  int a = 0;
  fo1(i, 7) {
    a = max(a, startAt(i,f,r,c));
  }

  cout << a;

  return 0;
}