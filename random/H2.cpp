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

unordered_map<int, int> var;
int vc = 0xfff;
stack<int> s;

inline bool isOp(int c) {
  return c == '+' || c == '-' || c == '*' || c == '/'; 
}

bool doOp() {
  if (s.size() < 3) return false;

  int ca = s.top(); s.pop();
  int cb = s.top(); s.pop();
  int op = s.top(); s.pop();
  if (isOp(ca) || isOp(cb) || !isOp(op)) {
    // ;-;
    s.emplace(op);
    s.emplace(cb);
    s.emplace(ca);
    return false;
  }
  int a = var[ca];
  int b = var[cb];
  if (op == '+')
    var[vc] = b+a;
  else if (op == '-')
    var[vc] = b-a;
  else if (op == '*')
    var[vc] = b*a;
  else if (op == '/')
    var[vc] = b/a;
  s.emplace(vc++);
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  char c; int k;
  while (n--) {
    cin >> c >> k;
    var[c] = k;
  }

  cin >> c;
  while (!cin.eof()) {
    s.emplace(c);
    while(doOp());
    cin >> c;
  }

  cout << var[s.top()];

  return 0;
}