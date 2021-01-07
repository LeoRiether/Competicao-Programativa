// Tested on https://www.spoj.com/problems/STRMATCH/
// Initial = 1 is the root node
// link[Initial] = 0

// useful stuff:
// sorting by len[u] is a topological sorting
// every distinct substring corresponds to exactly one *path* in the automaton
// every suffix corresponds to a path ending in a terminal node

const int SA = 2 * N;
const int Initial = 1;

int curLast = Initial, ID = Initial;
int len[SA], link[SA];
map<char, int> nxt[SA];

void push(char c) {
    int u = ++ID;
    len[u] = len[curLast] + 1;

    int p = curLast;

    // traverse suffixes of the string
    while (p && !nxt[p].count(c)) {
        nxt[p][c] = u;
        p = link[p];
    }

    if (!p) {
        // first time `c` has been added
        link[u] = Initial;
    } else {
        // some string x + c has already been added to the automaton!
        int q = nxt[p][c];

        if (len[q] == len[p] + 1) {
            // a node corresponding to x + c exists! (continous case)
            link[u] = q;
        } else {
            // discontinuous case
            int clone = ++ID;
            link[clone] = link[q];
            nxt[clone] = nxt[q];
            len[clone] = len[p] + 1;

            while (p && nxt[p][c] == q) {
                nxt[p][c] = clone;
                p = link[p];
            }

            link[u] = link[q] = clone;
        }
    }

    curLast = u;
}





///
/// Second version because ¯\_(ツ)_/¯
/// Tested on https://codeforces.com/gym/305539/problem/G
/// Uses O(N × A) memory
///

// Node 1 is the initial node of the automaton
const SA = 2 * N;
int last = 1;
int len[SA], link[SA];
array<int, 26> to[SA];
int lastID = 1;

void add(int c) {
    int u = ++lastID;
    len[u] = len[last] + 1;

    int p = last;
    last = u; // update last immediately
    for (; p > 0 && !to[p][c]; p = link[p])
        to[p][c] = u;

    if (p == 0) {
        // this was the first time the character c was added to the string
        link[u] = 1;
        return;
    }

    // there's a transition from a substring to { substring c } (from p to q)
    int q = to[p][c];
    if (len[q] == len[p] + 1) {
        // continuous transition
        // we can just add u to the endpos-set of q and be fine
        link[u] = q;
        return;
    }

    // non-continuous transition
    // we need to split q into two distinct endpos-sets
    int clone = ++lastID;
    len[clone] = len[p] + 1;
    link[clone] = link[q];
    link[q] = link[u] = clone;
    to[clone] = to[q];
    for (int pp = p; to[pp][c] == q; pp = link[pp])
        to[pp][c] = clone;
}

void print_automaton(const vector<int> &nodes) {
    printf("------------------------------\n");
    for (int u : nodes) {
        for (int c = 0; c < 26; c++) {
            if (to[u][c])
                printf("%d -- %c --> %d\n", u, c + 'a', to[u][c]);
        }
    }
    printf("------------------------------\n");
}