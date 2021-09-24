// Slight modification of https://github.com/mrsac7/CSES-Solutions/blob/master/src/2110%20-%20Substring%20Distribution.cpp
// Very nice implementation
int sa[N], rnk[N], tmp[N], lcp[N];

void build_lcp(const string& s) {
	int n = s.size();
    for (int i = 0, k = 0; i < n; i++) if (rnk[i] != n-1) {
        int j = sa[rnk[i] + 1];
        while (s[i + k] == s[j + k])
            k++;
        lcp[rnk[i]] = k;
        if (k) k--;
    }
}
 
void suffix_array(const string& s) {
	int n = s.size();
	int gap;

	auto comp = [&](int x, int y) {
		if (rnk[x] != rnk[y])
			return rnk[x] < rnk[y];
		x += gap; y += gap;
		return (x < n && y < n) ? rnk[x] < rnk[y] : x > y;
	};

    for (int i = 0; i < n; i++)
        sa[i] = i, rnk[i] = s[i];
 
    for (gap = 1;; gap <<= 1) {
        sort(sa, sa+n, comp);
        for (int i = 0; i < n-1; i++)
            tmp[i+1] = tmp[i] + comp(sa[i], sa[i+1]);
        for (int i = 0; i < n; i++)
            rnk[sa[i]] = tmp[i];
        if (tmp[n - 1] == n - 1)
            break;
    }
	build_lcp(s);
}

void print(const string& s) {
	int n = s.size();
	for (int i = 0; i < n; i++) {
		cout << sa[i] << ' ' << lcp[i] << ' ';
		for (int j = sa[i]; j < n; j++)
			cout << s[j];
		cout << endl;
	}
	cout << endl;
}

//
// Old implementation
// Please don't use
// the one above is much smaller
// maybe use the radixSort if you really need to 
//

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
  auto beg_ = beg;
  for (int i = 1; i >= 0; i--) {
    vector<vector<Node>> buckets(100005);
    for (beg = beg_; beg != end; beg++)
      buckets[beg->get(i)].push_back(*beg);

    beg = beg_;
    for (const auto& b : buckets)
      for (const auto& n : b)
        *(beg++) = n;
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
      // nn[i] = { sa[i], sa[(i+k)%n], i }; // alternative to sort cyclic shifts
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
