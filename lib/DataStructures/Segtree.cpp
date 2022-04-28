using info = int;
info st[2*N];

void build() {
    for (int i = N-1; i > 0; i--)
        st[i] = cat(st[i<<1], st[i<<1|1]);
}

info query(int l, int r) {
    info ans = 0;
    for (l+=N, r+=N; l < r; l>>=1, r>>=1) {
        if (l&1) ans = cat(ans, st[l++]);
        if (r&1) ans = cat(ans, st[--r]);
    }
    return ans;
}

void update(int i, info x) {
    st[i+=N] += x; // !
    for (i>>=1; i > 0; i>>=1)
        st[i] = cat(st[i<<1], st[i<<1|1]);
}

// k is 0-indexed
//! N must be a power of two!!! (actually, no, but for 2e5 elements, I could only make it AC with ≥2^18 elements. Yeah, just use a power of two)
int kth(int k) {
    int u = 1;
    while (u < N) {
        if (st[u<<1] <= k) {
            k -= st[u<<1];
            u = u<<1|1;
        } else {
            u = u<<1;
        }
    }

    return u - N;
}
