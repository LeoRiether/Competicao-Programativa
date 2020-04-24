// by tfg
ll fastexp(ll x, ll e) {
	ll ans = 1;
	for(; e > 0; e >>= 1) {
		if(e&1) ans *= x;
		x *= x;
	}
	return ans;
}