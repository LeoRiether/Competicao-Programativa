#include <iostream>
#include <vector>
using namespace std;

#define rep(i, l, r) for(int i = l; i < r; i++)
#define repb(i, l, r) for(int i = l; i > r; i--)

using vi = vector<int>;

// Elements above 1000 are not allowed
vi countingSort(vi& v) {
  int n = v.size();
  vi cnt(1001);

  // Count occurrences of number
  rep(i, 0, n)
    cnt[v[i]]++;

  // Make cnt[i] the position of the last i in the array
  rep(i, 1, n)
    cnt[i] += cnt[i-1];

  vi out(v.size());
  repb(i, n-1, -1)
    out[--cnt[v[i]]] = v[i];

  return out;
}


int main() {
  int n; cin >> n;
  vi v(n);
  rep(i, 0, n)
    cin >> v[i];

  auto sorted = countingSort(v);
  for (const auto i : sorted)
    cout << i << ' ';
  cout << endl;

  return 0;
}
