#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solveDecreasingSeqLen(int seqSize, vector<int> seq) {
    vector<int> seqCount(seqSize, 0);

    for (int i = 0; i < seqSize; i++) {
        seqCount[i] = 1;
        for (int j = 0; j < i; j++) {
            if (seq[i] < seq[j] && seqCount[i] < seqCount[j] + 1) {
                seqCount[i]++;
            }
        }
    }

    return *max_element(seqCount.begin(), seqCount.end());
}

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL);

    int seqSize;
    cin >> seqSize;

    vector<int> sequence(seqSize);
    for (int i = 0; i < seqSize; i++) {
        cin >> sequence[i];
    }

    cout << solveDecreasingSeqLen(seqSize, sequence);
}