#include <iostream>
#include <vector>
using namespace std;

struct Objeto {
  int w, v;
  Objeto(int w, int v) : w(w), v(v) { }
};

vector<Objeto> v;
vector<Objeto> ans;
vector<bool> taken;
int n; // Número de objetos
int W; // Capacidade total da mochila
int c = 0; // Conta quantas vezes a função é chamada

Objeto dp(int id) {
  c++;
  if (ans[id].w != 0) return ans[id]; // Pretty sure this is useless

  taken[id] = true;

  Objeto best{0,0}, aux{0,0};
  for (int i = 0; i < n; i++) {
    if (taken[i]) continue;
    aux = ans[i].w ? ans[i] : dp(i);
    if (aux.w <= W && aux.v*aux.w > best.v*best.w)
      best = aux;
  }

  taken[id] = false;

  if (v[id].w + best.w <= W && (v[id].v+best.v)*(v[id].w+best.w) > best.v*best.w) {
    best.w += v[id].w;
    best.v += v[id].v;
  }
  ans[id] = best;
  return best;
}

Objeto dp() {
  Objeto best{0,0}, aux{0,0};
  for (int i = 0; i < n; i++) {
    aux = dp(i);
    if (aux.w <= W && aux.v*aux.w > best.v*best.w)
      best = aux;
  }
  return best;
}

int main() {
  cin >> n >> W;
  v.reserve(n);
  ans.resize(n, Objeto(0,0));
  taken.resize(n, false);
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v.emplace_back(a, b);
  }

  Objeto m = dp();
  cout << "dp chamada " << c++ << " vezes" << endl;
  cout << m.w << ' ' << m.v << endl;

  return 0;
}