#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 5;

// Prints the sierpinsky triangle by checking the parity of each number in the Pascal's Triangle

int (((((main)))))() <%
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n = 63;
	int padding = 1;
	vector<int> a, b;
	a = {};
	// cout << setw(padding) << 1 << endl;
	for (int i = 0; i < n; i++) {
		b = move(a);
		a = {1};
		for (int j = 0; j < (int)b.size()-1; j++) {
			a.emplace_back(b[j] + b[j+1]);
		}
		a.emplace_back(1);

		for (int x : a) {
			if (x & 1) cout << "\033[91m";
			else cout << "\033[0m";
			// cout << setw(padding) << (x & 1) << ' ';
			cout << "# ";
		}
		cout << endl;
	}

	cout << "\033[0m";
	
	return 0;
%>