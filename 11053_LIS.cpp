// DP - LIS 
#include <iostream>
#include <vector>
using namespace std;
int DP[1000];

void LIS(int N, vector<int>& vect) {
    int max = 1;
    for (int i = 0; i < N; i++) {
        DP[i] = 1;
        for (int j = 0; j < i; j++) {
            if (vect[j] < vect[i] && DP[i] < DP[j] + 1)
                DP[i] = DP[j] + 1;
        }
        if (max < DP[i]) max = DP[i];
   }
    cout << max;
}


int main() {
    int N;
    cin >> N;

    int num;
    vector<int> vec;
    for (int i = 0; i < N; i++) {
        cin >> num;
        vec.push_back(num);
    }
    LIS(N, vec);
   
    return 0;
}