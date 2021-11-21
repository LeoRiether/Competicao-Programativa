// proud of this one
namespace kmp {
	string p;
	int neighbor[N];

	int walk(int u, char c) {
		while (u != -1 && (u+1 >= (int)p.size() || p[u + 1] != c)) // leader doesn't match
			u = neighbor[u];
		return p[u + 1] == c ? u+1 : u;
	}

	void build() {
		neighbor[0] = -1;
		for (int i = 1; i < (int)p.size(); i++)
			neighbor[i] = walk(neighbor[i-1], p[i]);
	}
}
