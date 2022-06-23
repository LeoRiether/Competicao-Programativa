// heavily based on https://ideone.com/YQX9jv,
// which adamant cites here https://codeforces.com/blog/entry/13959?#comment-196033
struct Eertree {
	int s[N];
	int n, last, sz;

	int len[N], link[N];
	int to[N][A];

	Eertree() {
		s[n++] = -1;
		len[1] = -1, link[1] = 1; // "backspace" root is 1
		len[0] = 0, link[0] = 1;  // empty root is 0 (to[backspace root][any char] = empty root)
		last = 2;
		sz = 2;
	}

	int get_link(int u) {
		while (s[n - len[u] - 2] != s[n - 1]) u = link[u];
		return u;
	} 

	void push(int c) {
		s[n++] = c;
		int p = get_link(last);
		if (!to[p][c]) {
			int u = ++sz;
			len[u] = len[p] + 2;
			link[u] = to[get_link(link[p])][c]; // may be 0 (empty), but never 1 (backspace)
			to[p][c] = u;
		}
		last = to[p][c];
	}
};

/// Old implementation:
/// Might be good idk
/// Honestly I don't even remember writing this code
///
// https://arxiv.org/pdf/1506.04862.pdf
// the eertree implementation I could come up with:
int link[N], len[N], to[A][N];
int uid, maxSuf;
const int Im = 1;
const int Empty = 2;

void init() {
    link[Im] = Im;
    len[Im] = -1;

    link[Empty] = Im;
    len[Empty] = 0;

    maxSuf = Empty;
    uid = Empty;
}

// Follow suffix links until we find a palindrome of type { s[i] Q s[i] }
int follow_links(const string& s, int u, int i) {
    auto j = [&]() { return i - len[u] - 1; };
    while (j() < 0 || s[i] != s[j()])
        u = link[u];
    return u;
}

int get_link(const string& s, int u, int i) {
    u = follow_links(s, u, i);
    int c = s[i] - 'a';
    return to[c][u];
}

bool add(const string& s, int i) {
    int u = follow_links(s, maxSuf, i);

    // Add a node if needed
    int c = s[i] - 'a';
    int& v = to[c][u];
    bool should_add_node = !v;
    if (should_add_node) {
        v = ++uid;
        len[v] = len[u] + 2;
        link[v] = u == Im ? Empty : get_link(s, link[u], i);
        debugf("added %d --%c--> %d, link = %d\n", u, s[i], v, link[v]);
    }

    maxSuf = v;
    return should_add_node;
}
