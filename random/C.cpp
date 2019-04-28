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
  vector<vi> v(n, vi(n));
  fo1(i, n) {
    fo1(j, n) {
      cin >> v[i][j];
    }
  }

  fo1(i, n) {
    int sl = 0, sc = 0;
    fo1(j, n) {
      sl += v[i][j];
    }
    fo1(j, n) {
      sc += v[j][i];
    }
    if (sc == n && sl == 1) {
      cout << "Popstar: aluno #" << i+1;
      return 0;
    }
  } 

  cout << "Nao ha popstar.";

  return 0;
}