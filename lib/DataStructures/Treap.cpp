const int N = 200005;

int tsz = 0;
int X[N], Y[N], L[N], R[N], sz[N];
bool flip[N];

//! Call this before anything else
void Build() {
    iota(Y+1, Y+N, 1);
	shuffle(Y+1, Y+N, rng); // rng :: mt19937
}

int new_node(int x) {
	int u = ++tsz;
	sz[u] = 1;
	X[u] = x;
	return u;
}

void Push(int u) { // also known as unlaze
	if (!u) return;
	if (flip[u]) {
		flip[u] = false;
		flip[L[u]] ^= 1;
		flip[R[u]] ^= 1;
		swap(L[u], R[u]);
	}
}

void Pull(int u) { // also known as fix
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
	Pull(u);
	return u;
}

// (s elements, N - s elements)
ii SplitSz(int u, int s) {
	if (!u) return {0, 0};
	Push(u);
	if (sz[L[u]] >= s) {
		auto [l, r] = SplitSz(L[u], s);
		L[u] = r;
		Pull(u);
		return { l, u };
	} else {
		auto [l, r] = SplitSz(R[u], s - sz[L[u]] - 1);
		R[u] = l;
		Pull(u);
		return { u, r };
	}
}

// (<= x, > x)
ii SplitVal(int u, int x) {
	if (!u) return {0, 0};
	Push(u);
	if (X[u] > x) {
		auto [l, r] = SplitVal(L[u], x);
        L[u] = r;
		Pull(u);
		return { l, u };
	} else {
		auto [l, r] = SplitVal(R[u], x);
        R[u] = l;
		Pull(u);
		return { u, r };
	}
}

int Insert(int u, int node) {
    Push(u);
    if (!u) return node;
    if (Y[node] < Y[u]) {
        tie(L[node], R[node]) = SplitVal(u, X[node]);
        u = node;
    }
    else if (X[node] < X[u]) L[u] = Insert(L[u], node);
    else R[u] = Insert(R[u], node);
    Pull(u);
    return u;
}

int Find(int u, int x) {
    return u == 0    ? 0 :
           x == X[u] ? u :
           x <  X[u] ? Find(L[u], x) :
                       Find(R[u], x);
}

void Free(int u) { /* node u can be deleted, maybe put in a pool of free IDs */ }

int Erase(int u, int key) {
    Push(u);
    if (!u) return 0;
    if (X[u] == key) {
        int v = Meld(L[u], R[u]);
        Free(u);
        u = v; 
    } else u = Erase(key < X[u] ? L[u] : R[u], key);
    Pull(u);
    return u;
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

