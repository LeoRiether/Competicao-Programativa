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
