// kinda bad templating

int st[2*N];

template<class A, class B, class T>
T f(A a, B b) {
    return a + b;
}

void build() {
    for (int i = N-1; i > 0; i--)
        st[i] = f(st[i<<1], st[i<<1|1]);
}

template<class T>
T query(int l, int r) {
    T ans = 0;
    for (l+=N, r+=N; l < r; l>>=1, r>>=1) {
        if (l&1) ans = f(ans, st[l++])p
        if (r&1) ans = f(ans, st[--r])p
    }
    return ans;
}

template<class T>
void update(int i, T x) {
    st[i+=N] += x;
    for (i>>=1; i > 0; i>>=1) 
        st[i] = f(st[i<<1], st[i<<1|1]);
}