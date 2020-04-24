#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
using namespace std;

// https://codeforces.com/blog/entry/53925
// https://codeforces.com/blog/entry/54090
// https://www.quora.com/q/negtyofjndusvnle/A-Dance-with-Mobius-Function

const int N = 1e5+5;

//
// Linear Sieve
//
vector<int> primes;
bool mark[N];

void linearSieve() {
    for (int i = 2; i < N; i++) {
        if (!mark[i]) primes.emplace_back(i);
        for (int j = 0; j < (int)primes.size() && i * primes[j] < N; j++) { // iterate over current primes
            mark[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

//
// Mobius Function
//
int mu[N];
bool mu_mark[N];
vector<int> mu_primes;

void mobius_linearsieve() {
    mu[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!mu_mark[i]) {
            // i is prime, thus mu[i] = -1
            mu[i] = -1;
        }

        for (int j = 0; j < (int)primes.size() && i * primes[j] < N; j++) { // iterate over current primes
            mu_mark[i * primes[j]] = true;

            // i * primes[j] is only accessed once here
            // and primes[j] is its smallest prime divisor

            if (i % primes[j] == 0) {
                mu[i * primes[j]] = 0; // i and primes[j] are not coprime
                break;
            } else {
                mu[i * primes[j]] = mu[i] * mu[primes[j]]; // i and primes[j] are coprime, mobius is multiplicative
            }
        }
    }
}

// int mu[N];
void mobius() {
    // are you kidding me
    memset(mu, 0, sizeof mu);
    mu[1] = 1;
    for(int i = 1; i < N; i++)
        for(int j = i + i; j < N; j += i)
            mu[j] -= mu[i];
}

//
// For testing purposes only:
//
vector<int> p2;
bool m2[N];
void sieve() {
    for (int i = 2; i < N; i++) {
        if (m2[i]) continue;
        p2.emplace_back(i);
        for (int j = 2*i; j < N; j += i) {
            m2[j] = true;
        }
    }
}

int main() {
    linearSieve();
    sieve();

    assert(primes.size() == p2.size());
    for (size_t i = 0; i < primes.size(); i++)
        assert(primes[i] == p2[i]);

    mobius();

    cout << "Just look at the mobius values below and see if they're right! Manually!" << endl;
    for (int i = 1; i < 20; i++)
        cout << "mu(" << i << ") = " << mu[i] << endl;

    // Just kidding, I'll put some tests here too
    vector<pair<int, int>> table = {
        { 1, 1 },
        { 4, 0 },
        { 6, 1 },
        { 30, -1 },
        { 10, 1 },
        { 20, 0 }
    };

    for (auto& p : table)
        assert(mu[p.first] == p.second);

    // and here
    for (int p : primes)
        assert(mu[p] == -1);

    cout << "Done" << endl;
}