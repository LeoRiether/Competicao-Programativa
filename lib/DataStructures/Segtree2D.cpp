// There's no update because I don't know how to do it

int t[N<<1][N<<1];

void build() {
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++)
            t[i+N][j+N] = val[i][j];
    }

    // I have no idea what I'm doing
    for (int i = 1; i < N<<1; i++)
        for (int j = N-1; j > 0; j--)
            t[i][j] = max(t[i][j<<1], t[i][j<<1|1]);

    for (int i = N-1; i > 0; i--)
        for (int j = 1; j < N<<1; j++)
            t[i][j] = max(t[i<<1][j], t[i<<1|1][j]);
}

int query(int li, int lj, int ri, int rj) {
    int ans = 0;

    li = N + min(li, n+1);
    lj = N + min(lj, m+1);
    ri = N + max(ri, 1);
    rj = N + max(rj, 1);

    auto query_j = [&](int i, int lj, int rj) {
        for (; lj < rj; lj >>= 1, rj >>= 1) {
            if (lj & 1) ans = max(ans, t[i][lj++]);
            if (rj & 1) ans = max(ans, t[i][--rj]);
        }
    };

    for (; li < ri; li >>= 1, ri >>= 1) {
        if (li & 1) query_j(li++, lj, rj);
        if (ri & 1) query_j(--ri, lj, rj);
    }

    return ans;
}