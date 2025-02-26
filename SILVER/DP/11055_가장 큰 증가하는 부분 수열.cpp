#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solveIncreasingSeqSum(int seqSize, vector<int> seq) {
    vector<int> seqSum = seq;

    for (int i = 0; i < seqSize; i++) {
        for (int j = 0; j < i; j++) {
            if (seq[i] > seq[j] && seqSum[j] > (seqSum[i] - seq[i])) {
                seqSum[i] = seqSum[j] + seq[i];
            }
        }
    }

    return *max_element(seqSum.begin(), seqSum.end());
}

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL);

    int seqSize;
    cin >> seqSize;

    vector<int> sequence(seqSize);
    for (int i = 0; i < seqSize; i++) {
        cin >> sequence[i];
    }

    cout << solveIncreasingSeqSum(seqSize, sequence);
}