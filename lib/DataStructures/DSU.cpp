int P[N], S[N];
void Build() {
    iota(P, P+N, 0);
    fill(S, S+N, 1);
}

int Find(int i) {
    while (i != P[i])
        i = P[i] = P[P[i]];
    return i;
}

void Union(int i, int j) {
    if ((i=Find(i)) == (j=Find(j))) return;
    if (S[i] > S[j]) swap(i, j);
    P[i] = j;
    S[j] += S[i];
}
