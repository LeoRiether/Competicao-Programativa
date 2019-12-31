// Lius version

int pf[N];
 
void pfunc(char s[], int n){
	pf[0] = -1; int i = 0, j = pf[0];
	while(i < n){
		while(j >= 0 && s[i] != s[j]) j = pf[j];
		pf[++i] = ++j;
	}
}
 
int kmp(char t[], char p[], int n, int m, int ini){
	int j = 0;
	for(int i = ini; i < n; i++){
		while(j >= 0 && t[i] != p[j]) j = pf[j];
		j++;
	}
	return j;
}