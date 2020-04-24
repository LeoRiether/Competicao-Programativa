// You can implement Dijkstra with buckets (Dial's Algorithm) with this!
// Tested on https://codeforces.com/contest/1340/problem/C
// BFS 0-1 with deque runs twice as fast and uses much less memory, use that whenever possible
// Maybe CircularBucketQueue works as well, you can try that
template<class T, int BucketMax=N>
struct BucketQueue {
    vector<T> buckets[BucketMax];
    int start = 0;
    int sz = 0;

    void push(int key, const T value) {
        buckets[key].push_back(value);
        assert(key >= start);
        sz++;
    }

    bool empty() {
        return sz == 0;
    }

    //! Please verify that the queue is not empty before calling
    // Returns { key, value }
    pair<int, T> pop() {
        assert(!empty());
        while (buckets[start].empty()) ++start;

        auto r = buckets[start].back();
        buckets[start].pop_back();
        --sz;
        return { start, r };
    }
};

// This seems to work! At least for 0-1 BFS... Runs faster and uses way less memory.
template<class T, int MaxWeight>
struct CircularBucketQueue {
    vector<T> buckets[MaxWeight+1];
    int start = 0;
    int sz = 0;

    void push(int cost, const T value) {
        cost += start;
        if (cost >= MaxWeight+1) cost -= MaxWeight+1;
        buckets[cost].push_back(value);
        sz++;
    }

    bool empty() {
        return sz == 0;
    }

    //! Please verify that the queue is not empty before calling
    T pop() {
        assert(!empty());
        while (buckets[start].empty()) {
            ++start;
            if (start == MaxWeight+1) start = 0;
        }

        auto r = buckets[start].back();
        buckets[start].pop_back();
        --sz;
        return r;
    }
};


