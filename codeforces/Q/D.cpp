#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<bool> s;
int n,b,a;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n>>b>>a;

  s.resize(n);
  int aux;
  fo1(i, n) cin >> aux, s[i] = aux == 1;

  int k {0};
  int ta{a}, tb{b};
  while (k < n && (ta > 0 || tb > 0)) {
    if (s[k] && tb > 0) {
      tb--; 
      if (ta < a)
        ta++;
      else if (ta > tb) {
        
      }
    }
    else if (ta > 0) {
      ta--;
    }
    else {
      tb--;
    }
    k++;
  }

  cout << k;

  return 0;
}