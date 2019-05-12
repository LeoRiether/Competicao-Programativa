#include <bits/stdc++.h>
using namespace std;

#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << endl;
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
using ll = long long; using vi = vector<int>; using ii = pair<int,int>;
const int oo = 0x3f3f3f3f;

struct Client {
  int index;
  ll arrival, otime;
};

bool cmp(Client& a, Client& b) {
  if (a.arrival == b.arrival) {
    return a.index < b.index;
  }
  return a.arrival < b.arrival;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; ll k; cin >> n >> k;
  vector<pair<ll, char>> time(n+1);
  vector<Client> clients;
  clients.reserve(n);
  int c1, c2;
  fo1(i, n) {
    cin >> c1 >> c2;
    clients.push_back({i+1, c1, c2});
  }
  sort(all(clients), cmp);

  queue<ll> A, B;
  ll t = 0;
  for (const auto c : clients) {
    // Take out all clients that have completed orders
    while (!A.empty() && A.front() <= c.arrival) A.pop();
    while (!B.empty() && B.front() <= c.arrival) B.pop();

    if (sz(A) <= sz(B)) {
      if (sz(A) == 0)
        t = c.arrival + c.otime;
      else
        t = A.back() + c.otime;
      A.push(t);
      time[c.index] = { t, 'A' };
    } else {
      if (sz(B) == 0)
        t = c.arrival + c.otime*k;
      else
        t = B.back() + c.otime*k;
      B.push(t);
      time[c.index] = { t, 'B' };
    }
  }


  rep(i, 1, n+1) {
    cout << time[i].second << ' ' << time[i].first << '\n';
  } 
  return 0;
}