#include <iostream>

using namespace std;

typedef pair<long long, long long> pii;

pii solveTwoFiveFactorNum(int end) {
    long long twoNum = 0, fiveNum = 0;

    for (long long i = 2; i <= end; i *= 2) {
        twoNum += end / i;
    }

    for (long long i = 5; i <= end; i *= 5) {
        fiveNum += end / i;
    }

    return {twoNum, fiveNum};
}

int main() {
    int n, m;
    cin >> n >> m;

    pii factoN = solveTwoFiveFactorNum(n);
    pii factoNM = solveTwoFiveFactorNum(n - m);
    pii factoM = solveTwoFiveFactorNum(m);

    long long twoNum = factoN.first - (factoNM.first + factoM.first);
    long long fiveNum = factoN.second - (factoNM.second + factoM.second);

    cout << min(twoNum, fiveNum);
}