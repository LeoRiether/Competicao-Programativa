// 2021 version

const int N = 1e5 + 5;
int t[N<<2], lz[N<<2];

void prop(int u) {
	if (!lz[u]) return;
	t[u] += lz[u];
	if ((u << 1) < (N<<2)) {
		lz[u<<1] += lz[u];
		lz[u<<1|1] += lz[u];
	}
	lz[u] = 0;
}

void update(int tl, int tr, int x, int u = 1, int l = 0, int r = N) {
	prop(u);
	if (l >= tr || r <= tl) return;
	if (l >= tl && r <= tr) {
		lz[u] += x;
		prop(u);
		return;
	}

	int mid = (l + r) / 2;
	update(tl, tr, x, u<<1, l, mid);
	update(tl, tr, x, u<<1|1, mid, r);
	t[u] = min(t[u<<1], t[u<<1|1]);
}

int query(int tl, int tr, int u = 1, int l = 0, int r = N) {
	prop(u);
	if (l >= tr || r <= tl) return 1e9;
	if (l >= tl && r <= tr) return t[u];

	int mid = (l + r) / 2;
	return min(
			query(tl, tr, u<<1, l, mid),
			query(tl, tr, u<<1|1, mid, r));
}

