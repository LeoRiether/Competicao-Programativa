// https://github.com/joseleite19/icpc-notebook/blob/master/code/graph/kosaraju.cpp
vector<int> g[N], gi[N]; // grafo invertido
bitset<N> vis; int comp[N]; // componente conexo de cada vertice
vector<int> S;

void dfs(int u){
    vis[u] = 1;
    for(auto v: g[u]) if(!vis[v]) dfs(v);
    S.push_back(u);
}

void scc(int u, int c){
    vis[u] = 1; comp[u] = c;
    for(auto v: gi[u]) if(!vis[v]) scc(v, c);
}

void kosaraju(int n){
    for(int i=1;i<=n;i++) vis[i] = 0;
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    for(int i=1;i<=n;i++) vis[i] = 0;
    reverse(S.begin(), S.end());
    for (int u : S) if (!vis[u]) scc(u, u);
}
