#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

#define fo1(i, n) for (int i = 0; i < n; i++)

double** a;
double* A;

int main() {
    int n;
    cin >> n;

    A = (double*)malloc(sizeof(double) * n * n);
    a = (double**)malloc(sizeof(double*) * n);
    fo1(i, n)
        a[i] = &A[i*n];

    fo1(i, n) fo1(j, n) {
        int x; cin >> x;
        a[i][j] = x;
    }

    double det = 1;
    for (int k = 0; k < n-1; k++) {
        if (a[k][k] == 0) {
            // Troca uma linha com líder nulo por uma linha boa
            bool found = false;
            for (int i = k+1; i < n-1 && !found; i++) {
                if (a[i][k] != 0) {
                    found = true;
                    det *= -1;
                    swap(a[i], a[k]);
                }
            }
            if (!found) continue;
        }
        
        // Actual Gauss stuff
        for (int i = k+1; i < n; i++) {
            double t = -a[i][k]/a[k][k];
            for (int j = k; j < n; j++) {
                a[i][j] += a[k][j] * t;
            }
        }
    }

    fo1(i, n) {
        fo1(j, n)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    cout << endl;

    for (int k = 0; k < n; k++)
        det *= a[k][k];

    cout << det << endl;
    return 0;
}