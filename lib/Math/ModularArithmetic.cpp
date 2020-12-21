using ll = long long;
int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
int mul(ll x, ll y) { return x * y % mod; }
int pwr(int x, int e) {
    int ans = 1;
    for (; e > 0; e >>= 1, x = mul(x, x)) {
        if (e & 1)
            ans = mul(ans, x);
    }
    return ans;
}

int fac[N], inv[N];
void build_ncr() {
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = mul(fac[i - 1], i);
    inv[N - 1] = pwr(fac[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--)
        inv[i] = mul(inv[i + 1], i + 1);
}
int ncr(int n, int r) {
    if (n - r < 0)
        return 0;
    return mul(fac[n], mul(inv[r], inv[n - r]));
}