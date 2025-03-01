#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num, numCount;
    cin >> num >> numCount;

    vector<int> sumUp(num + 1, 0);

    sumUp[0] = 1;

    for (int i = 1; i <= numCount; i++) {
        for (int j = 1; j <= num; j++) {
            sumUp[j] = (sumUp[j - 1] + sumUp[j]) % 1'000'000'000;
        }
    }

    cout << sumUp[num];
}