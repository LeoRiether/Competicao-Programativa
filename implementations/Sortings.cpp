#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using vi = vector<int>;
using std::swap;
using std::cout;
using std::endl;
using ll = long long;

#define sz(x) int((x).size())

//
// This shall be my greatest creation yet to be seen
//

// Returns the number of swaps
using sortFn_t = ll (*)(vi&);

ll insertion(vi& A) {
  int n = sz(A);
  ll s = 0;
  for (int i = 1; i < n; i++)
    for (int j = i; j > 0 && A[j-1] > A[j]; j--)
      swap(A[j-1], A[j]), s++;
  return s;
}

ll bubble(vi& A) {
  int n = sz(A);
  ll s = 0;
  for (int i = 0; i < n-1; i++)
    for (int j = 1; j < n-i; j++)
      if (A[j-1] > A[j])
        swap(A[j-1], A[j]), s++;
  return s;
}

ll counting(vi& A) {
  static const int N = 100005;
  vi c(N);
  for (const auto i : A)
    c[i]++;
  
  for (int i = 1; i < N; i++)
    c[i] += c[i-1];

  vi B = A;
  for (const auto i : B)
    A[--c[i]] = i;

  return 2*sz(A) + N;
}

ll radix(vi& A) {
  for (int k = 1; k <= 1e9; k *= 10) {
    // Counting sort
    vi c(10);
    for (const auto i : A)
      c[(i/k) % 10]++;
    
    for (int i = 1; i < 10; i++)
      c[i] += c[i-1];

    vi B = A;
    for (int i = sz(B)-1; i >= 0; i--)
      A[--c[(B[i]/k) % 10]] = B[i];
  }
  return sz(A)*20;
}

ll shell(vi& A) {
  int n = sz(A);
  ll s = 0;
  // static const vi gaps = { 701, 301, 132, 57, 23, 10, 4, 1 };

  vi gaps; gaps.reserve(18);
  for (int i = 2; i < n; i <<= 1)
    gaps.emplace_back(i - 1);

  for (auto gap = gaps.rbegin(); gap != gaps.rend(); gap++) {
    for (int i = *gap; i < n; i++)
      for (int j = i; j >= *gap && A[j-*gap] > A[j]; j--)
        swap(A[j-*gap], A[j]), s++;
  }
  return s;
}

ll selection(vi& A) {
  int n = sz(A);
  ll s = 0;
  for (int i = 0; i < n-1; i++) {
    int mn = i;
    s += n-i+1;
    for (int j = i+1; j < n; j++) {
      if (A[j] < A[mn])
        mn = j;
    }
    swap(A[i], A[mn]);
  }
  return s;
}

// TODO: Heap sort can be implemented in-place!
// 1-based heap
#define left(x) ((x)<<1)
#define right(x) ((x)<<1|1)
#define parent(x) ((x)>>1)

ll heap_insert(vi& h, int x) {
  h.emplace_back(x);
  int i = sz(h)-1;
  int s = 0;
  while (i > 1 && h[parent(i)] > h[i]) {
    swap(h[parent(i)], h[i]);
    s++;
    i = parent(i);
  }
  return s;
}

ll heap_removeTop(vi& h) {
  int n = sz(h); 
  swap(h[1], h[n-1]);
  h.pop_back();
  n--;
  int i = 1;
  int s = 1;
  for (;;) {
    int best = i;
    if (left(i) < n && h[left(i)] < h[best])
      best = left(i);
    if (right(i) < n && h[right(i)] < h[best])
      best = right(i);

    if (best == i) break;
    swap(h[best], h[i]);
    s++;
    i = best;
  }
  return s;
}

ll heap(vi& A) {
  // Not the best heap-building method, I know
  vi h = { -0x3f3f3f3f };
  h.reserve(sz(A)+1);
  int s = 0;
  for (const auto i : A)
    s += heap_insert(h, i);
  
  for (int i = 0; i < sz(A); i++) {
    A[i] = h[1];
    s += heap_removeTop(h);
  }
  return s;
}


ll mergeAux(vi& A, vi& B, int l, int r) {
  if (r-l <= 1) return 0;

  int s = 0;
  int mid = (l+r)/2;
  s += mergeAux(A, B, l, mid);
  s += mergeAux(A, B, mid, r);

  std::copy(A.begin()+l, A.begin()+r, B.begin()+l);
  int i = l, j = mid;
  int p = l;
  s += r-l;
  while (i < mid && j < r) {
    if (B[i] < B[j])
      A[p++] = B[i++];
    else
      A[p++] = B[j++];
  }
  while (i < mid) A[p++] = B[i++];
  while (j < r)   A[p++] = B[j++];

  return s;
}

ll merge(vi& A) {
  vi B(sz(A));
  return mergeAux(A, B, 0, sz(A));
}

int median(int a, int b, int c) {
  if (a > b && a > c) // a is max
    return b > c ? b : c;
  if (b > a && b > c) // b is max
    return a > c ? a : c;
  return a > b ? a : b; // c is max
}

ll quickAux(vi& A, int l, int r) {
  if (r-l <= 1 || l > r) return 0;

  ll s = 0;

  // int pivot = A[(l+r-1)/2];
  int pivot = median(A[l], A[(l+r-1)/2], A[r-1]);
  int i = l, j = r-1;
  for (;;) {
    while (A[i] < pivot) i++;
    while (A[j] > pivot) j--;

    if (i >= j) break;
    s++; // ??
    swap(A[i], A[j]);
    i++, j--;
  }

  j++;
  s += quickAux(A, l, j);
  s += quickAux(A, j, r);
  return s;
}

ll quick(vi& A) {
  return quickAux(A, 0, sz(A));
}

ll gnome(vi& A) {
  int i = 0;
  int n = sz(A);
  ll s = 0;
  while (i < n) {
    if (i == 0 || A[i-1] <= A[i])
      i++;
    else swap(A[i-1], A[i]), i--;
    s++;
  }
  return s;
}

// Needs long long long
bool checkSorted(vi&);
ll bogosort(vi& A) {
  ll s = 0;
  int n = sz(A);
  while (!checkSorted(A, n)) {
    // Generate random permutation
    for (int i = 0; i < n-1; i++) {
      int j = rand()%(n-i) + i;
      swap(A[i], A[j]);
      s++;
    }
  }
  return s;
}

ll sleep() {
  return 0; // TODO: implementation
}

bool checkSorted(vi& A) {
  for (int i = sz(A)-1; i > 0; i--)
    if (A[i-1] > A[i])
      return false;
  return true;
}

int main() {
  sortFn_t fns[] = {
    insertion, bubble, counting, radix,
    shell, selection, heap, merge, quick,
    gnome
  };

  std::string names[] = {
    "Insertion", "Bubble", "Counting", "Radix",
    "Shell", "Selection", "Heap", "Merge", "Quick",
    "Gnome"
  };

  vi A(1000);
  for (int i = sz(A); i >= 0; i--)
    A[i] = i;
  std::random_shuffle(A.begin(), A.end());

  int n = sizeof(fns)/sizeof(*fns);
  for (int i = 0; i < n; i++) {
    vi B = A;
    ll s = fns[i](B);
    cout << names[i] << " Sort: ";
    cout << (checkSorted(B) ? "[\033[92mSorted\033[0m]\n" : "[\033[91mUnsorted!\033[0m]\n");
    cout << "\t\033[92m" << s << "\033[0m operations\n";
    cout << "\t\033[92m" << s/sz(A) << "\033[0m times sz(A) operations" << endl;
  }

  return 0;
}
