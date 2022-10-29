using ull = unsigned long long;

struct Bitset {
    vector<ull> v; 
    Bitset(int n) {
        v.resize((n + 63) / 64, 0);
    }
 
    inline bool test(ull i) const { return (v[i / 64] >> (i % 64ull)) & 1ull; }
    inline void set(ull i) { v[i / 64] |= 1ull << (i % 64ull); }
    inline void reset(ull i) { v[i / 64] &= ~(1ull << (i % 64ull)); }
    inline void set(ull i, bool b) {
        if (b) set(i);
        else reset(i);
    }
 
    inline void shr() {
        int n = v.size();
        for (int i = 0; i < n; i++) {
            v[i] >>= 1ull;
            if (i+1 < n) v[i] |= (v[i+1] & 1ull) << 63ull;
        }
    }
 
    int msb() const {
        int n = v.size();
        for (int i = n-1; i >= 0; i--) {
            if (v[i] != 0)
                return (63 - __builtin_clzll(v[i])) + (i * 64);
        }
        return -1;
    }
 
    Bitset operator|(const Bitset& r) const {
        int n = v.size();
        Bitset ans(64 * n);
        for (int i = 0; i < n; i++)
            ans.v[i] = v[i] | r.v[i];
        return ans;
    }
 
    bool operator>(const Bitset& r) const {
        int n = v.size();
        for (int i = n-1; i >= 0; i--) {
            if (v[i] != r.v[i])
                return v[i] > r.v[i];
        }
        return false; // ==
    }
    bool operator<(const Bitset& r) const {
        int n = v.size();
        for (int i = n-1; i >= 0; i--) {
            if (v[i] != r.v[i])
                return v[i] < r.v[i];
        }
        return false; // ==
    }
 
};

ostream& operator<<(ostream& os, const Bitset& bs) {
    bool z = false;
    for (int i = 64*(int)bs.v.size()-1; i >= 0; i--) {
        bool b = bs.test(i);
        if (z || b)
            os << b;
        z |= b;
    }
    return os;
}

