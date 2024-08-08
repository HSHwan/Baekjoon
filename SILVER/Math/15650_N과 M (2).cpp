#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int N,M;
vector<int> perm;
vector<bool> temp;

int main(){
    cin >> N >> M;

    FOR(i, N) {
        perm.push_back(i + 1);
        temp.push_back(false);
    }

    FOR(i, M) {
        temp[i] = true;
    }

    do {
        for (int i = 0; i < N; i++) {
            if (temp[i]) {
                cout << perm[i] << ' ';
            }    
        }
        cout << '\n';
    } while (prev_permutation(temp.begin(), temp.end()));

}