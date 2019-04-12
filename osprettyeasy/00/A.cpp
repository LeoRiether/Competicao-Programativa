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

  char qrank, qsuit;
  cin >> qrank >> qsuit;

  char rank, suit;
  fo1 (i, 5) {
    cin >> rank >> suit;
    if (rank == qrank || suit == qsuit) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";

  return 0;
}