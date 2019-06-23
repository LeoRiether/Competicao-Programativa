#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

#define LSB(x) ((x)&(-(x)))

struct Matrix {
  int w, h;
  vi data;
  Matrix() {}
  Matrix(int w, int h) : w(w), h(h) {
    data.resize(w*h);
  }

  int& operator()(int i, int j) {
    i--; j--;
    return data[i*w+j];
  }
};

struct BIT {
  Matrix m;
  BIT(int w, int h) {
    m = Matrix(w, h);
  }

  int query(int x, int y) {
    int y1 = y;
    int sum = 0;
    while (x > 0) {
      y = y1;
      while (y > 0) {
        sum += m(y, x);
        y -= LSB(y);
      }
      x-= LSB(x);
    }
    return sum;
  }

  void update(int x, int y, int d) {
    int y1 = y;
    while (x <= m.w) {
      y = y1;
      while (y <= m.h) {
        m(y, x) += d;
        y += LSB(y);
      }
      x+= LSB(x);
    }
  }

  int sum(int a, int b, int x, int y) {
    a--; b--;
    return query(x,y) - query(a,y) - query(x,b) + query(a,y);
  }

};


int main() {
  int n; cin >> n;
  BIT bit(n,n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x; cin >> x;
      bit.update(j,i,x);
    }
  }

  cout << bit.sum(1,1,4,4) << endl;
  cout << bit.sum(1,1,2,2) << endl;
  cout << bit.sum(2,2,4,4) << endl;
  cout << bit.sum(2,2,3,3) << endl;
}