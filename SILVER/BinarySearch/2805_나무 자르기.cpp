#include <iostream>
#include <vector>
#define MAX 2'000'000'000
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int treeNum, treeNeed;
    cin >> treeNum >> treeNeed;

    vector<int> treeHeight(treeNum);
    for (int i = 0; i < treeNum; i++) {
        cin >> treeHeight[i];
    }

    long low = 0, high = MAX;
    while (low <= high) {
        long mid = (low + high) >> 1;
        long allTreeLen = 0;
        for (int height : treeHeight) {
            allTreeLen += (height > mid) ? height - mid : 0;
        }
        if (allTreeLen < treeNeed) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << high;
}