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

int next(int& v) {
  v *=v;
  v = v / 100;
  v = v % 10000;
  return v;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  fo3(i, n) {
    cout << "Teste #" << i << '\n';
    set<int> s;
    int v; cin >> v;
    do {
      cout << v << ' ';
      s.insert(v);
    } while(s.count(next(v)) == 0);
    cout << '\n';
  }

  return 0;
}