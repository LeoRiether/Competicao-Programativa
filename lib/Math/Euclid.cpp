// a*x + b*y = gcd(a, b),  <gcd, x, y>
// C++17 version of https://github.com/joseleite19/icpc-notebook/blob/master/code/math/euclides.cpp
using triple_t = tuple<int, int, int>;
triple_t gcd(int a, int b) {
	if (b == 0) return { a, 1, 0 };
	auto [q, w, e] = gcd(b, a % b);
	return { q, e, w - e * (a / b) };
}