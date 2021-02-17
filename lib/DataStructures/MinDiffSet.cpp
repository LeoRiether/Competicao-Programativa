// Data structure that supports
// 1. Inserting elements
// 2. Removing elemetns
// 3. Querying the minimum difference between two elements of the set
// I'll call it ds, both for "data structure" and "difference set"
// 2/10, too many ifs
namespace ds {
    set<int> s;
    multiset<int> diffs;

    void push(int x) {
        if (s.empty()) {
            s.emplace(x);
            return;
        }

        auto n = s.lower_bound(x+1); // next

        if (n == s.end()) {
            // x is the last element
            auto p = prev(n);
            diffs.emplace(x - (*p));
        } else if (n == s.begin()) {
            // x is the first element
            diffs.emplace((*n) - x);
        } else {
            // x is somewhere in the middle
            auto p = prev(n);
            int d = (*n) - (*p);
            diffs.erase(diffs.find(d));
            diffs.emplace((*n) - x);
            diffs.emplace(x - (*p));
        }

        s.emplace_hint(n, x);
    }

    void erase(int x) {
        if (s.empty()) return; // ???
        if (s.size() == 1) {
            s.erase(s.find(x));
            return;
        }

        auto n = s.lower_bound(x+1);

        if (n == s.end()) {
            // x is the last element
            auto p = prev(prev(n));
            diffs.erase(diffs.find(x - (*p)));
        } else if (n == next(s.begin())) {
            // x is the first element
            diffs.erase(diffs.find((*n) - x));
        } else {
            // x is somewhere in the middle
            auto p = prev(prev(n));
            diffs.erase(diffs.find((*n) - x));
            diffs.erase(diffs.find(x - (*p)));
            diffs.emplace((*n) - (*p));
        }

        s.erase(s.find(x));
    }

    int minDiff() {
        return diffs.empty() ? oo : *diffs.begin();
    }

    void clear() {
        s.clear();
        diffs.clear();
    }
}