#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull solveGCD(ull a, ull b) {
    ull tmp, n;

    if (a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }

    while (b) {
        n = a % b;
        a = b;
        b = n;
    }

    return a;
}

int main() {
    ios::sync_with_stdio(false), cout.tie(NULL);
    ull a,b;
    cin >> a >> b;

    ull gcd = solveGCD(a, b);

    while (gcd--) {
        cout << '1';
    }
}