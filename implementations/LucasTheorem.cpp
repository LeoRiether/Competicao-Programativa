// table[m_i][n_i] = m_i choose n_i, for m_i and n_i digits of the binary representation of m and n
int table[2][2] = {
	{1, 0},
	{1, 1}
};

// (m choose n) mod 2
int comb_mod_2(int m, int n) {
	int ans = 1;
	while (m > 0 || n > 0) {
		ans *= table[m & 1][n & 1];
		m >>= 1;
		n >>= 1;
	}
	return ans;
}

/**
 * (m choose n) is congruent mod p to the
 * product of (m_i choose n_i), for m_i and n_i digits of m and n in base p
 * 
 * Also "Teorema de Lucas fala q binômio C(n, k) % 2 = 1 sse k é mask de n"
 */ 