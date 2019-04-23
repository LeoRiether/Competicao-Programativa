#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define fo2(i, n) for (int i = (n); i >= 0; i--)
#define fo3(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll M = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  ll l,r; cin >> l >> r;
  l--; r--;

  ll sum = 0;
  ll diff = 0;
  ll i = 0, neven = 2, nodd = 1;
  ll block = 0;
  ll aux;

  // Count till the block before l
  while (i+(1ll<<block) <= l) {
    i += 1ll<<block;
    if (block & 1)
      neven = (neven + (2ll<<block)%M) % M;
    else
      nodd = (nodd + (2ll<<block)%M) % M;
    block++;
  }

  // Sum the current block until l
  // ll n = (l%M + (M - i%M))%M - 1;
  ll n = l - i - 1;
  if (block & 1) {
    // aux = (neven + (n<<1ll)%M) % M;
    aux = (neven + (n%M<<1ll)%M) % M;
    diff = ((neven + aux)%M * (n+1)%M) % M;
  }
  else {
    // aux = (nodd + (n<<1ll)%M) % M;
    aux = (nodd + (n%M<<1ll)%M) % M;
    diff = ((nodd + aux)%M * (n+1)%M) % M;
  }
  diff >>= 1;

  // Sum till the block before r
  while (i+(1ll<<block) <= r) {
    i += 1ll<<block;
    if (block == 35) { 
      cout << "breakpoint\n"; 
    }
    if (block & 1) {
      aux = (neven + (2ll<<block)%M) % M;
      // sum = (sum + ( ((neven + (aux-2))%M * (1ll<<block)%M)>>1 )%M) % M;
      sum = (sum + ( ((neven + (aux-2))%M * ((1ll<<(block-1))%M)) )%M) % M;
      neven = aux;
    }
    else {
      aux = (nodd + (2ll<<block)%M) % M;
      sum = (sum + ( ((nodd + (aux-2))%M * ((1ll<<(block-1))%M)) )%M) % M;
      nodd = aux;
    }
    block++;
  }

  // Sum the current block until r
  // n = (r%M + (M - i%M)) % M;
  n = r - i;
  cout << r << ' ' << i <<' ' << n << endl;
  if (block & 1) {
    // aux = (neven + (n<<1ll)%M) % M;
    aux = (neven + (n%M<<1ll)%M) % M;
    sum = (sum + (((neven + aux)%M * (n+1)%M)>>1ll) % M) % M;
  }
  else {
    // aux = (nodd + (n<<1ll)%M) % M;
    aux = (nodd + (n%M<<1ll)%M) % M;
    sum = (sum + (((nodd + aux)%M * (n+1)%M)>>1ll) % M) % M;
  }

  cout << sum << endl << diff << endl;
  cout << (sum + (M - diff)) % M << endl;
  // cout << (sum - diff) % M;

  return 0;
}