#include <bits/stdc++.h>
using namespace std;

#define fo1(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
using ll = long long; using vi = vector<int>; using ii = pair<int,int>;
const int oo = 0x3f3f3f3f; const ll OO = ll(oo)*oo;
#ifndef DEBUG
#define endl '\n'
#define debugf(...)
#define debug(...)
#else
#define debugf(...) printf(__VA_ARGS__)
#define debug(...) __VA_ARGS__
#endif
const int N = 20;
const ll M = 1000000007;

ll F[1<<N], G[1<<N], H[1<<N];
ll R[1<<N];

void add(ll& x, ll y) {
    x += y;
    if (x >= M) x -= M;
    if (x < 0) x += M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    n = 1<<n;
    fo1(i, n)
        cin >> F[i];
    fo1(i, n)
        cin >> G[i];
    fo1(i, n)
        cin >> H[i];

    // Transforms:
    // F[i] = sum(f[j]) for all j submask of i
    // Same for G[i] and H[i]
    for (int b = 1; b < n; b <<= 1) {
        for (int u = 0; u < n; u += (b<<1)) {
            for (int l = 0; l < b; l++) {
                int m = u|l;
                add(F[m|b], F[m]);
                add(G[m|b], G[m]);
                add(H[m|b], H[m]);
            }
        }
    }

    // for (int b = n>>1; b >= 1; b >>= 1) {
    //     for (int u = (n-1) & ~(2*b-1); u >= 0; u -= (b<<1)) {
    //         for (int l = b-1; l >= 0; l--) {
    //             int m = u|l;
    //             add(F[m|b], -F[m]);
    //             add(G[m|b], -G[m]);
    //             add(H[m|b], -H[m]);
    //             debugf("%d <- -%d\n", m|b, m);
    //         }
    //     }
    // }

    // Transforms:
    // R[x] = sum(F[i] * G[j] * H[k]) for all i|j|k submask of x
    fo1(i, n) {
        // acho que nem precisa de parênteses aqui
        R[i] = (((F[i] * G[i]) % M) * H[i]) % M;
    }

    // Inverse transform (probably):
    // R[x] = sum(F[i] * G[j] * H[k]) for all i|j|k == x
    for (int b = n>>1; b >= 1; b >>= 1) {
        for (int u = (n-1) & ~(2*b-1); u >= 0; u -= (b<<1)) {
            for (int l = b-1; l >= 0; l--) {
                int m = u|l;
                add(R[m|b], -R[m]);
            }
        }
    }

    // Transforms:
    // R[x] = sum(F[i] * G[j] * H[k]) for all i|j|k supermask of x (aka the answer)
    for (int b = 1; b < n; b <<= 1) {
        for (int u = 0; u < n; u += (b<<1)) {
            for (int l = 0; l < b; l++) {
                int m = u|l;
                add(R[m], R[m|b]);
            }
        }
    }

    // psum
    rep(i, 1, n) {
        add(R[i], R[i-1]);
    }

    // WA
    cout << R[n-1] << endl;

    return 0;
}