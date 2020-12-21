#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct SegTree2D {
	void init(int _n, int _m) {
		n = _n, m = _m;
		tree.assign(2 * n, std::vector<int>(2 * m, 0));
	}

	void upd(int x, int y, int val) {
		assert(0 <= x && x < n && 0 <= y && y < m);
		x += n, y += m;
		tree[x][y] = val;
		for(int j = y / 2; j > 0; j /= 2) {
			tree[x][j] = gcd(tree[x][2*j], tree[x][2*j+1]);
		}
		for(x /= 2; x > 0; x /= 2) {
			tree[x][y] = gcd(tree[2*x][y], tree[2*x+1][y]);
			for(int j = y / 2; j > 0; j /= 2) {
				tree[x][j] = gcd(tree[x][2*j], tree[x][2*j+1]);
			}
		}
	}

	std::vector<int> getCover(int l, int r, int N) {
		l = std::max(0, l);
		r = std::min(N, r);
		std::vector<int> ans;
		for(l += N, r += N; l < r; l /= 2, r /= 2) {
			if(l & 1) ans.push_back(l++);
			if(r & 1) ans.push_back(--r);
		}
		return ans;
	}

	int qry(int l1, int r1, int l2, int r2) {
		auto c1 = getCover(l1, r1, n);
		auto c2 = getCover(l2, r2, m);
		int ans = 0;
		for(auto i : c1) for(auto j : c2) ans = gcd(tree[i][j], ans);
		return ans;
	}

	int n, m;
	std::vector<std::vector<int>> tree;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	while(std::cin >> q) {
		SegTree2D tree;
		tree.init(2020, 2020);
		while(q--) {
			std::string str;
			std::cin >> str;
			int x, y, d;
			std::cin >> x >> y >> d;
			int wtf = x + y + 1000;
			y = x - y + 1000;
			x = wtf;
			if(str == "QUERY") {
				std::cout << tree.qry(x - d, x + d + 1, y - d, y + d + 1) << '\n';
			} else {
				tree.upd(x, y, d);
			}
		}
	}
}