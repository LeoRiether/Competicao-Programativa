struct mint {
	int x;
	mint(int _x = 0) : x(_x) { }
	mint operator +(const mint rhs) const { return x + rhs.x >= mod ? x + rhs.x - mod : x + rhs.x; }
	mint operator *(const mint rhs) const { return mint((ll)x * rhs.x % mod); }
	mint operator -(const mint rhs) const { return *this + (mod - rhs.x); }
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
bool built_ncr = false;
void build_ncr() {
	built_ncr = true;
	fac[0] = 1;
	for (int i = 1; i < N; i++)
		fac[i] = fac[i-1] * i;
	ifac[N-1] = fac[N-1].inv();
	for (int i = N-2; i >= 0; i--)
		ifac[i] = ifac[i+1] * (i+1);
}
mint ncr(int n, int r) {
	assert(built_ncr);
    if (n - r < 0) return 0;
	return fac[n] * ifac[r] * ifac[n - r];
}

