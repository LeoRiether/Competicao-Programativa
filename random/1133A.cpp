#include <bits/stdc++.h>
using namespace std;

int main() {
  int m0, m1;
  char a,b,c,d;
  scanf("%c%c:%c%c\n", &a, &b, &c, &d);
  m0 = ((a-'0')*10 + b -'0')*60 + ((c-'0')*10 + d-'0');
  scanf("%c%c:%c%c", &a, &b, &c, &d);
  m1 = ((a-'0')*10 + b -'0')*60 + ((c-'0')*10 + d-'0');

  int f { (m1+m0)>>1 };
  printf("%02d:%02d", f/60, f%60);

  return 0;
}