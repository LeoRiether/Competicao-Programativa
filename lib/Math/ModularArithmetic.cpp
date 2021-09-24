struct mint {
	int x;
	mint(int _x = 0) : x(_x) { }
	mint operator +(mint rhs) { return x + rhs.x >= mod ? x + rhs.x - mod : x + rhs.x; }
	mint operator *(mint rhs) { return mint((ll)x * rhs.x % mod); }
	mint operator -(mint rhs) { return *this + (mod - rhs.x); }
	mint inv() { return this->pwr(mod - 2); }
	mint pwr(ll e) {
		mint t = x;
		mint ans = 1;
		for (; e > 0; e >>= 1, t = t * t)
			if (e & 1) ans = ans * t;
		return ans;
	}
};

mint fac[N], ifac[N];
void build_ncr() {
	fac[0] = 1;
	for (int i = 1; i < N; i++)
		fac[i] = fac[i-1] * i;
	ifac[N-1] = fac[N-1].inv();
	for (int i = N-2; i >= 0; i--)
		ifac[i] = ifac[i+1] * (i+1);
}
mint ncr(int n, int r) {
    if (n - r < 0) return 0;
	return fac[n] * ifac[r] * ifac[n - r];
}

//
// what I used to write:
//
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
