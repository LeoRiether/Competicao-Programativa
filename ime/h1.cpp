#include <bits/stdc++.h>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int MOD = 1'000'000'007;
const double EPS = 0.000'000'001;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

const int N = 1'000'010;
int phi[N];

void sieve()
{
    for(int i = 0; i < N; i++)
        phi[i] = i;

    for(ll i = 2; i < N; i++)
    {
        if(phi[i] == i)
        {
            phi[i] = i - 1;

            for(ll j = i + i; j < N; j += i)
                phi[j] = (phi[j] / i) * (i - 1);
        }
    }
}

int main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cout.precision(10);

    sieve();

    int q;
    cin >> q;

    while(q--)
    {
        int a, b;
        cin >> a >> b;

        if(gcd(a, b) != 1)
            cout << -1 << endl;
        else
        {
            cout << phi[b] << endl;
        }
    }

    return 0;
}