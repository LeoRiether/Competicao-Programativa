// Solution to https://codeforces.com/gym/305539/problem/B
// https://codeforces.com/gym/305539/submission/99821952
#include <bits/stdc++.h>
using namespace std;

// I have no idea what I'm doing

#ifdef DEBUG
#define debug(...) __VA_ARGS__
#else
#define endl '\n'
#define debug(...)
#endif
#define debugf(...) debug(printf(__VA_ARGS__))

using ll = long long;
const int N = 5e4 + 5;
const int E = 2 * N;
const int K = 32;
const int oo = 0x3f3f3f3f;

vector<int> g[N]; // original tree edges

#define rank my_rank

int in[N], out[N], T;
int ein[E], eout[E], t[E<<1], eT;
int rank[N];
void dfs_time(int u, int p = 0) {
    rank[u] = rank[p] + 1;

    ein[u] = ++eT;
    t[eT + E] = u;

    in[u] = ++T;
    for (int v : g[u]) if (v != p) {
        dfs_time(v, u);
        t[(++eT) + E] = u;
    }
    out[u] = T;
    eout[u] = eT;
}

int take(int u, int v) { return ein[u] < ein[v] ? u : v; }
void fix(int u) { t[u] = take(t[u<<1], t[u<<1|1]); }
void build_st() {
    for (int i = E-1; i > 0; i--)
        fix(i);
}

int query(int l, int r) {
    int ans = 0;
    for (l+=E, r+=E; l < r; l>>=1, r>>=1) {
        if (l&1) ans = take(ans, t[l++]);
        if (r&1) ans = take(ans, t[--r]);
    }
    return ans;
}

int get_lca(int u, int v) {
    if (ein[u] > ein[v]) swap(u, v);
    return query(ein[u], eout[v]+1);
}

// does u cover v?
int covers(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}


int a[K];
int cost[K];
vector<int> vt[N]; // virtual tree edges

void build_costs(int n) {
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++)
            cost[i] = min(cost[i], cost[j] + cost[i - j]);
    }
}

int cnt[N];

void build_cnt(int u, int p = 0) {
    for (int v : vt[u]) if (v != p) {
        build_cnt(v, u);
        cnt[u] += cnt[v];
    }
}

ll solve(int u, int p = 0) {
    ll ans = 0;
    for (int v : vt[u]) if (v != p) {
        ll x = solve(v, u);
        ans += x;

        ll dist = rank[v] - rank[u];
        ans += dist * cost[cnt[v]];
    }
    return ans;
}

int (((((((main)))))))() {
    cin.tie(0)->sync_with_stdio(false);

    ein[0] = oo;

    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs_time(1);
    build_st();

    int queries;
    cin >> queries;
    while (queries--) {
        int k; cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        sort(a, a+k, [&](int u, int v) { return in[u] < in[v]; });

        // read costs
        for (int i = 1; i <= k; i++)
            cin >> cost[i];
        build_costs(k);

        debug(
            cout << "cost = ";
            for (int i = 1; i <= k; i++)
                cout << cost[i] << ' ';
            cout << endl;
        );

        int nk = k;
        for (int i = 0; i < k-1; i++) {
            a[nk++] = get_lca(a[i], a[i+1]);
        }
        k = nk;

        a[k++] = 1; // !

        sort(a, a+k, [&](int u, int v) { return in[u] < in[v]; });

        // dedup
        nk = 0;
        for (int i = 0; i < k; i++) {
            if (i == 0 || a[i] != a[i-1]) {
                a[nk++] = a[i];
            }
        }
        k = nk;

        debug(
            cout << "virtual nodes: ";
            for (int i = 0; i < k; i++)
                cout << a[i] << ' ';
            cout << endl;
        )

        // clear previous tree
        for (int i = 0; i < k; i++) {
            vt[a[i]].clear();
        }

        int root;
        stack<int> s;
        for (int i = 0; i < k; i++) {
            int u = a[i];
            while (!s.empty() && !covers(s.top(), u))
                s.pop();

            if (s.empty()) {
                root = u;
                debugf("root = %d\n", u);
            } else {
                vt[s.top()].push_back(u);
                debugf("%d -> %d\n", s.top(), u);
            }
            s.push(u);
        }

        build_cnt(root);
        cout << solve(root) << endl;

        // clear cnt
        for (int i = 0; i < k; i++) {
            cnt[a[i]] = 0;
        }
    }

    return 0;
}
