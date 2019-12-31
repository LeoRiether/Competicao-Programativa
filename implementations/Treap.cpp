// answer to https://codeforces.com/problemset/problem/1011/E

#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
#ifndef DEBUG
#define endl '\n'
#define debugf(...)
#define debug(...)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#else
#define debugf(...) printf(__VA_ARGS__)
#define debug(...) __VA_ARGS__
mt19937 rng('m'+'e'+'r'+'r'+'y' + 'c'+'h'+'r'+'i'+'s'+'t'+'m'+'a'+'s');
#endif
const int N = 300005;

int cnt[N], f[N], sz[N], X[N], Y[N], L[N], R[N], tsz = 0;

map<int, int> howmany;

void fix(int u) {
    if (!u) return;

    sz[u] = sz[L[u]] + 1 + sz[R[u]];
    cnt[u] = cnt[L[u]] + f[u] + cnt[R[u]];
}

void build() {
    for (int i = 1; i < N; i++)
        Y[i] = i;
    shuffle(Y+1, Y+N, rng);
}

// [<=x, >x)
ii split(int u, int x) {
    if (!u) return {0, 0};

    int l, r;
    if (X[u] <= x) {
        tie(l, r) = split(R[u], x);
        R[u] = l;
        fix(u);
        return { u, r };
    } else {
        tie(l, r) = split(L[u], x);
        L[u] = r;
        fix(u);
        return { l, u };
    }
}

// root = meld(l, r);
int meld(int l, int r) {
    int u;
    if (!l || !r) {
        u = l ? l : r;
    } else if (Y[l] < Y[r]) {
        u = l;
        R[u] = meld(R[u], r);
    } else {
        u = r;
        L[u] = meld(l, L[u]);
    }

    fix(u);
    return u;
}

int _insert(int u, int v) {
    if (!u) return v;

    if (Y[v] < Y[u]) {
        int l, r;
        tie(l, r) = split(u, X[v]);
        L[v] = l;
        R[v] = r;
        u = v;
    } else {
        if (X[v] <= X[u]) L[u] = _insert(L[u], v);
        else R[u] = _insert(R[u], v);
    }

    fix(u);
    return u;
}

// howmany[x] should be > 0 before calling this function
void inc(int u, int x) {
    if (x < X[u]) {
        inc(L[u], x);
    } else if (x > X[u]) {
        inc(R[u], x);
    } else {
        f[u]++;
    }

    fix(u);
}

void insert(int& u, int x) {
    if (howmany[x] > 0) {
        inc(u, x);
        return;
    }

    howmany[x]++;

    int v = ++tsz;
    X[v] = x;
    cnt[v] = 1;
    f[v] = 1;
    sz[v] = 1;
    L[v] = 0;
    R[v] = 0;
    u = _insert(u, v);
}

void inorder(int u) {
    if (!u) return;

    inorder(L[u]);
    printf("<%d:%d> ", X[u], f[u]);
    inorder(R[u]);
}

void preorder(int u) {
    printf("(");
    if (u) {
        printf("<%d/%d> ", X[u], Y[u]);
        preorder(L[u]);
        printf(" ");
        preorder(R[u]);
    }
    printf(")");
}

int kth_smallest(int u, int k) {
    while (u) {
        if (k > cnt[u]) return -1;

        if (k <= cnt[L[u]] + f[u] && k > cnt[L[u]]) return X[u];

        if (cnt[L[u]] >= k) {
            u = L[u];
        } else {
            k -= cnt[L[u]] + f[u];
            u = R[u];
        }
    }

    return -1;
}

int32_t (((((main)))))() <%
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    build();

    int n, q;
    cin >> n >> q;

    int root = 0;

    {
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            insert(root, x);
        }
    }

    // Answer queries
    int l, r;
    while (q--) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            tie(l, r) = split(root, x);
            int add = cnt[l];
            root = meld(l, r);
            insert(root, x + add);
        } else if (t == 2) {
            tie(l, r) = split(root, x);
            cout << cnt[l] << endl;
            root = meld(l, r);
        } else {
            int ans = kth_smallest(root, x);
            if (ans == -1) cout << "invalid" << endl;
            else cout << ans << endl;
        }

        // inorder(root);
    }

    return 0;
%>