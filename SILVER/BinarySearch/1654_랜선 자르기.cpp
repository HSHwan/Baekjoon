#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int k, n;
    cin >> k >> n;

    vector<long long> lanWire(k);
    for (int i = 0; i < k; i++) {
        cin >> lanWire[i];
    }

    long long start = 1;
    long long end = 2'147'483'647;

    while (start <= end) {
        long long mid = (start + end) >> 1;
        int lanWireCount = 0;
        for (int wire : lanWire) {
            lanWireCount += wire / mid;
        }
        if (lanWireCount >= n) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << end;
}