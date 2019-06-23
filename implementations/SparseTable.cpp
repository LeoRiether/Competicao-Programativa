#include <bits/stdc++.h>
using namespace std;

constexpr int MaxN = 100005;
constexpr int MaxST = 25;
int logt[MaxN+1];

// Min sparse table
int st[MaxST][MaxN];

inline int rangeMin(int l, int r) {
  int k = logt[r-l+1];
  return min(st[k][l], st[k][r - (1<<k) + 1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Preprocess log(n)
  logt[1] = 0;
  for (int i = 2; i <= MaxN; i++)
    logt[i] = logt[i/2] + 1;

  // Build sparse table
  for (int i = 0; i < n; i++)
    st[0][i] = a[i];

  for (int k = 1; k < MaxST; k++) {
    for (int i = 0; i < n; i++) {
      if (i + (1<<(k-1)) < n)
        st[k][i] = min(st[k-1][i], st[k-1][i + (1<<(k-1))]);
      else
        st[k][i] = st[k-1][i];
    }
  }

  // Process queries
  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    cout << rangeMin(l, r) << endl;
  }

  return 0;
}