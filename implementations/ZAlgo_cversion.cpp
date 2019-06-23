#include <stdio.h>

// #define printf(x...)

int strlen(const char* s) {
  int i = -1;
  while (s[++i]);
  return i;
}

char* strbuild(char* dest, char* a, char* b) {
  int k = 0;
  for (int i = 0; a[i]; dest[k++] = a[i++]);
  dest[k++] = '$';
  for (int i = 0; b[i]; dest[k++] = b[i++]);
  return dest+k;
}

void buildZ(int* z, char* s) {
  z[0] = 0;
  int n = strlen(s);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    z[i] = i+z[i-l] < r ? z[i-l] : 0;
    while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
      l = i; r = i+z[i]; z[i]++;
    }
  }
}

int main() {
  int z[100005];

  char pat[] = "ACBACDA";
  char text[] = "ACBACDACBACBACDA"; // match on 0 and 6
  char str[100005];
  strbuild(str, pat, text);
  int n = strlen(str);
  buildZ(z, str);

  printf("Z Array: ");
  for (int i = 0; i < n; i++)
    printf("%d ", z[i]);
  puts("");

  int plen = strlen(pat);
  for (int i = 0; i < n; i++) {
    if (z[i] == plen)
      printf("Match found on %d.\n", i - plen-1);
  }

  return 0;
}