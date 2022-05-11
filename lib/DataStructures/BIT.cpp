int bit[N];

int sum(int i) {
    int s = 0;
    for(i++; i > 0; i -= i & -i)
        s += bit[i];
    return s;
}

void add(int i, int delta) {
    for(i++; i < N; i += i & -i)
        bit[i] += delta;
}
