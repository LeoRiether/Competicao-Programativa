#include <stdio.h>

int read() {
  int x;
  scanf("%d", &x);
  return x;
}

int min(int x, int y) {
  if (x < y) 
    return x;
  return y;
}
int max(int x, int y) {
  if (x > y) 
    return x;
  return y;
}

int main() {
  int n = read();

  int mn = 0x3f3f3f3f, mx = -0x3f3f3f3f;
  int x;
  while(n--) {
    x = read();
    mn = min(mn, x);
    mx = max(mx, x);
  }

  printf("min = %d; max = %d", mn, mx);

  return 0;
}