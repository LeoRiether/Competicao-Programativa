#include <bits/stdc++.h>
using namespace std;

// This is actually so easy
// not sure why I didn't learn it earlier

int LIS_DP(vector<int>& a) {
  int n = a.size();
  int dp[n]; // dp[i] = size of LIS ending at i

  int ans = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j]) // we can extend this LIS
        dp[i] = max(dp[i], dp[j] + 1);
    }
    ans = max(ans, dp[i]); // the answer could end at any i
  }
  return ans;
}

// O(nlogn) LIS with binary search
// it's actually really, really easy to code
int LIS_Good(vector<int>& a) {
  vector<int> ans;
  for (const auto x : a) {
    auto lb = lower_bound(ans.begin(), ans.end(), x);
    if (lb == ans.end())
      ans.emplace_back(x);
    else
      *lb = x; 
  }
  return ans.size();
}

int main() {
  vector<int> A = {1,2,4,8,3,4,5,6,7};

  cout << LIS_DP(A) << endl;
  cout << LIS_Good(A) << endl;

  return 0;
}