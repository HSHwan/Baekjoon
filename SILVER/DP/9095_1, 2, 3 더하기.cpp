#include <iostream>
#include <vector>
#define MAX 10

using namespace std;

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL); cout.tie(NULL);

    int testcase, n;
    cin >> testcase;

    vector<int> intSumNums(MAX + 1, 0);
    intSumNums[1] = 1;
    intSumNums[2] = 2;
    intSumNums[3] = 4;

    for (int i = 4; i <= MAX; i++) {
        intSumNums[i] = intSumNums[i - 1] + intSumNums[i - 2] + intSumNums[i - 3];
    }

    while (testcase--) {
        cin >> n;
        cout << intSumNums[n] << '\n';
    }

}