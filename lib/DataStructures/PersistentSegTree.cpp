int ID;
const int Log = 18;
const int B = N * Log + 4 * N;
int L[B], R[B];
using info = int; 
info X[B];

int Build(int l = 0, int r = N) {
    int u = ++ID;
    if (r - l <= 1) {
        X[u] = 0;
        return u;
    }

    int mid = (l + r) / 2;
    L[u] = Build(l, mid);
    R[u] = Build(mid, r);
    X[u] = X[L[u]] + X[R[u]];
    return u;
}

int Update(int u, int pos, info value, int l = 0, int r = N) {
    int v = ++ID;
    if (r - l <= 1) {
        X[v] = X[u] + value;
        return v;
    }

    int mid = (l + r) / 2;
    if (pos < mid)
        L[v] = Update(L[u], pos, value, l, mid), R[v] = R[u];
    else
        L[v] = L[u], R[v] = Update(R[u], pos, value, mid, r);
    X[v] = X[L[v]] + X[R[v]];
    return v;
}

// [l, r)
info Query(int u, int tl, int tr, int l = 0, int r = N) {
    if (l >= tr || r <= tl || r - l <= 0)
        return 0;

    if (l >= tl && r <= tr)
        return X[u];

    int mid = (l + r) / 2;
    return Query(L[u], tl, tr, l, mid) + Query(R[u], tl, tr, mid, r);
}

// -1 if there's no element in a position >=pos, otherwise the index of the
// lower bound
int LowerBound(int u, int pos, int l = 0, int r = N) {
    if (X[u] == 0 || r <= pos)
        return -1;

    if (r - l <= 1)
        return l;

    int mid = (l + r) / 2;
    int ansLeft = LowerBound(L[u], pos, l, mid);
    if (ansLeft != -1) // found the lower bound in the left node
        return ansLeft;
    return LowerBound(R[u], pos, mid, r); // not found in the left, let's try the right node
}

int Kth(int u, int k, int l = 0, int r = N) {
    while (r - l > 1) {
        int cnt = X[L[u]];
        int mid = (l + r) / 2;
        if (cnt >= k)
            u = L[u], r = mid;
        else
            u = R[u], l = mid, k -= cnt;
    }
    return l;
}
