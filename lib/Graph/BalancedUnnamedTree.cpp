#include <bits/stdc++.h>
using namespace std;

#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << endl;
#define fo1(i, n) for (int i = 0; i < (n); i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define mp(a, b) make_pair((a), (b))
typedef long long ll; typedef vector<int> vi; typedef pair<int,int> ii;
const int oo = 0x3f3f3f3f;

// Cache efficiency? No, never heard of it
struct UnnamedNode {
  int l, r;
  int mx;
  int rank;
  UnnamedNode* lnode;
  UnnamedNode* rnode;
};

// Meu TCC
class BalancedUnnamedTree {
private:
  UnnamedNode* root;

  void Fragment(UnnamedNode* node, int x) {
    if (!node->lnode && !node->rnode) {
      node->lnode = new UnnamedNode{node->l, x, x-node->l, 0, nullptr, nullptr};
      node->rnode = new UnnamedNode{x, node->r, node->r-x, 0, nullptr, nullptr};
    } else {
      if (node->lnode->l <= x && node->lnode->r >= x)
        Fragment(node->lnode, x);
      else 
        Fragment(node->rnode, x);
    }
    Balance(node);
    node->rank = GetRank(node);
    node->mx = max(node->lnode->mx, node->rnode->mx);
  }

  void SlideLeft(UnnamedNode* node) {
    UnnamedNode* lnodeCopy = node->lnode;
    node->lnode = node->rnode; // Rnode slides to the left
    node->rnode = node->lnode->rnode;
    node->lnode->rnode = node->lnode->lnode;
    node->lnode->lnode = lnodeCopy;
    node->lnode->r = node->lnode->rnode->r;
    node->lnode->l = node->lnode->lnode->l;
    node->lnode->rank = GetRank(node->lnode);
    node->lnode->mx = max(node->lnode->lnode->mx, node->lnode->rnode->mx);   
    node->rnode->mx = max(node->rnode->lnode->mx, node->rnode->rnode->mx);
  }
  void SlideRight(UnnamedNode* node) {
    UnnamedNode* rnodeCopy = node->rnode;
    node->rnode = node->lnode; // Lnode slides to the right
    node->lnode = node->rnode->lnode;
    node->rnode->lnode = node->rnode->rnode;
    node->rnode->rnode = rnodeCopy;
    node->rnode->l = node->rnode->lnode->l;
    node->rnode->r = node->rnode->rnode->r;
    node->rnode->rank = GetRank(node->rnode);
    node->rnode->mx = max(node->rnode->lnode->mx, node->rnode->rnode->mx);
    node->lnode->mx = max(node->lnode->lnode->mx, node->lnode->rnode->mx);    
  }

  void SlideUpLeft(UnnamedNode* node) {
    UnnamedNode* lnodeCopy = node->lnode;

    // Rnode->Lnode slides up to the left
    node->lnode = node->rnode->lnode;

    // Fix rnode
    node->rnode->lnode = node->lnode->rnode;
    node->rnode->l = node->rnode->lnode->l;
    node->rnode->rank = GetRank(node->rnode);    
    node->rnode->mx = max(node->rnode->lnode->mx, node->rnode->rnode->mx);

    // Fix lnode
    node->lnode->rnode = node->lnode->lnode;
    node->lnode->lnode = lnodeCopy;
    node->lnode->l = node->lnode->lnode->l;
    node->lnode->r = node->lnode->rnode->r;
    node->lnode->mx = max(node->lnode->lnode->mx, node->lnode->rnode->mx);
  }
  void SlideUpRight(UnnamedNode* node) {
    UnnamedNode* rnodeCopy = node->rnode;

    // Lnode->Rnode slides up to the right
    node->rnode = node->lnode->rnode;

    // Fix lnode
    node->lnode->rnode = node->rnode->lnode;
    node->lnode->r = node->lnode->rnode->r;
    node->lnode->rank = GetRank(node->lnode);
    node->lnode->mx = max(node->lnode->lnode->mx, node->lnode->rnode->mx);

    // Fix rnode
    node->rnode->lnode = node->rnode->rnode;
    node->rnode->rnode = rnodeCopy;
    node->rnode->r = node->rnode->rnode->r;
    node->rnode->l = node->rnode->lnode->l;
    node->rnode->mx = max(node->rnode->lnode->mx, node->rnode->rnode->mx);
  }

  inline void Balance(UnnamedNode* node) {
    if (abs(node->lnode->rank - node->rnode->rank) <= 1) return;

    if (node->rnode->rank > node->lnode->rank) { // Right-heavy
      if (node->rnode->rnode && node->rnode->rnode->rank >= node->rnode->lnode->rank) { // Right-right-heavy
        SlideLeft(node);
      } else { // Right-left heavy
        SlideUpLeft(node);
      }
    } else { // Left-heavy
      if (node->lnode->lnode && node->lnode->lnode->rank >= node->lnode->rnode->rank) { // Left-left heavy
        SlideRight(node);
      } else { // Left-right heavy
        SlideUpRight(node);
      }
    }
  }


public:
  BalancedUnnamedTree(int w) {
    root = new UnnamedNode{0, w, w, 0, nullptr, nullptr};
  }

  ll Max() { return ll(root->mx); }

  void Fragment(int x) { Fragment(root, x); }

  inline int GetRank(UnnamedNode* node) { return node->lnode ? 1+max(node->lnode->rank, node->rnode->rank) : 0; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int w, h, q; cin >> w >> h >> q;

  BalancedUnnamedTree xaxis(w), yaxis(h);

  char c; int f;
  while (q--) {
    cin >> c >> f;
    if (c == 'H') {
      yaxis.Fragment(f);
    } else if (c == 'V') {
      xaxis.Fragment(f);
    }

    cout << xaxis.Max() * yaxis.Max() << '\n';
  }
  
  return 0;
}