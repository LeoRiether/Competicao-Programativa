#include <bits/stdc++.h>
using namespace std;

#define pb emplace
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
#define SORT(x) sort((x).begin(), (x).end())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

unordered_map<char, int> var;
stack<char> s;
queue<char> q;

pii read2() {
  int a = q.back(); q.pop_back();
  int b = q.back(); q.pop_back();
  return make_pair(a, b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  char c;
  int x;
  fo1(i, n) {
    cin >> c >> x;
    var[c] = x;
  }

  cin >> c;
  while (!cin.eof()) {
    q.emplace(c);
    cin >> c;
  }

  int a, b;
  while(!q.empty()) {
    c = q.back(); cs.pop_back();
    if (c == '+') {
      auto [a,b] = read2();
      var['$'] = a+b;
      s.emplace('$');
    } else if (c == '-') {
      a = var[s.top()]; s.pop();
      b = var[s.top()]; s.pop();
      var['$'] = a-b;
      s.emplace('$');
    } else if (c == '*') {
      a = var[s.top()]; s.pop();
      b = var[s.top()]; s.pop();
      var['$'] = a*b;
      s.emplace('$');
    } else if (c == '/') {
      a = var[s.top()]; s.pop();
      b = var[s.top()]; s.pop();
      var['$'] = a/b;
      s.emplace('$');
    } else { // number
      s.emplace(c);
    }
  }

  cout << var[s.top()];

  return 0;
}