#include <ext/random>
__gnu_cxx::sfmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
__gnu_cxx::sfmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution gen(a, b); // [a, b], inclusive
