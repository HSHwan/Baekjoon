#include <iostream>
#include <algorithm>
#define MAX 1'000

using namespace std;

int withdrawTime[MAX];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int peopleNum;
    cin >> peopleNum;

    for (int i = 0; i < peopleNum; i++)
        cin >> withdrawTime[i];

    sort(withdrawTime, withdrawTime + peopleNum);

    int minTimeSum = withdrawTime[0];
    for (int i = 1; i < peopleNum; i++) {
        withdrawTime[i] += withdrawTime[i - 1];
        minTimeSum += withdrawTime[i];
    }

    cout << minTimeSum;
}