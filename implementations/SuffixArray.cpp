#include <bits/stdc++.h>
using namespace std;

struct Node {
  int first, second;
  int index;

  bool operator!=(Node& x) {
    return x.first != first || x.second != second;
  }

  bool operator<(Node& x) {
    if (first == x.first)
      return second < x.second;
    return first < x.first;
  }

  int get(int i) {
    return i == 0 ? first : second;
  }
};

void radixSort(vector<Node>::iterator beg, vector<Node>::iterator end) {
  vector<vector<Node>> buckets(100005);
  auto beg_ = beg;
  for (int i = 1; i >= 0; i--) {
    for (beg = beg_; beg != end; beg++)
      buckets[beg->get(i)].push_back(*beg);

    beg = beg_;
    for (const auto& b : buckets)
      for (const auto& n : b)
        *(beg++) = n;

    buckets.assign(257, {});
  }
}

vector<int> buildSuffixArray(string& s) {
  int n = s.size();
  vector<int> sa(n);
  vector<Node> nn(n);

  if (n == 1) return sa;

  // Build initial rankings
  for (int i = 0; i < n; i++) 
    sa[i] = s[i];

  // Prefix doubling
  for (int k = 1; k < n; k <<= 1) {
    // Build pair rankings
    for (int i = 0; i < n; i++) {
      nn[i] = { sa[i], i+k<n ? sa[i+k] : 0, i };
    }

    radixSort(nn.begin(), nn.end());
    
    // Update rankings
    int r = 1;
    Node last = nn[0];
    for (int i = 0; i < n; i++) {
      if (last != nn[i]) 
        r++;
      sa[nn[i].index] = r;
      last = nn[i];
    }
  }

  // Normalize indices
  for (int i = 0; i < n; i++)
    sa[i]--;

  return sa;
}

int main() {
  string s; cin >> s;

  vector<int> sa = buildSuffixArray(s);

  for (const auto c : s)
    cout << "  " << c;
  cout << endl;

  for (const auto i : sa)
    cout << setw(3) << i;
  cout << endl;

  return 0;
}