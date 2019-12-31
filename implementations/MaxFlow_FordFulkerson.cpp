// Not tested!

struct MF {
    bitset<N> seen;
    int g[N][N];
    int source, sink;

    MF(int source, int sink) : source(source), sink(sink) { }

    int add(int u, int v, int cap=1) {
        g[u][v] += cap;
    }

    int go(int u, int flow) {
        if (u == sink) return flow;

        int x;
        for (int v = 0; v < N; v++) {
            if (!g[u][v] || !seen[i]) continue;

            x = go(v, min(flow, g[u][v]));
            if (x > 0) {
                g[u][v] -= x;
                g[v][u] += x;
                return x;
            }
        }
        return 0;
    }

    int maxflow() {
        int flow = 0;
        int x;
        seen.reset();
        while ((x = go(source, 0x3f3f3f3f)) > 0) {
            flow += x;
            seen.reset();
        }
        return flow;
    }
};
