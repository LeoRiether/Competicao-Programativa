const int N = 200005;

int tsz = 0;
int X[N], Y[N], L[N], R[N], sz[N];
bool flip[N];

int new_node(int x) {
	int u = ++tsz;
	sz[u] = 1;
	X[u] = x;
	return u;
}

void Push(int u) {
	if (!u) return;
	if (flip[u]) {
		flip[u] = false;
		flip[L[u]] ^= 1;
		flip[R[u]] ^= 1;
		swap(L[u], R[u]);
	}
}

void Fix(int u) {
	if (!u) return;
	sz[u] = sz[L[u]] + 1 + sz[R[u]];
}

// root = Meld(l, r);
int Meld(int l, int r) {
	Push(l); Push(r);

	int u;
	if (!l || !r) {
		u = l ? l : r;
	} else if (Y[l] < Y[r]) {
		u = l;
		R[u] = Meld(R[u], r);
	} else {
		u = r;
		L[u] = Meld(l, L[u]);
	}

	Fix(u);
	return u;
}

// (less than pos, greater than or equal to pos]
ii Split(int u, int pos) {
	if (!u) return {0, 0};

	Push(u);

	if (pos <= sz[L[u]]) {
		auto [l, r] = Split(L[u], pos);
		L[u] = r;
		Fix(u);
		return { l, u };
	} else {
		auto [l, r] = Split(R[u], pos - sz[L[u]] - 1);
		R[u] = l;
		Fix(u);
		return { u, r };
	}
}

void preorder(int u) {
	cout << "(";
	if (u) {
		cout << X[u] << ' ';
		preorder(L[u]);
		cout << ' ';
		preorder(R[u]);
	}
	cout << ")";
}

//! Call this before anything else
void Build() {
	for (int i = 1; i < N; i++)
		Y[i] = i;
	shuffle(Y+1, Y+N, rng);
}

// Reversing an interval:
//
// auto [l, r] = Split(root, left);
// auto [itv, rr] = Split(r, right - left + 1);
// flip[itv] ^= 1;
// r = Meld(itv, rr);
// root = Meld(l, r);
//
// or
// 
// auto [l, r] = Split(root, right+1);
// auto [ll, lr] = Split(l, left);