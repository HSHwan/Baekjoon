#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i, N) for (int i = 1; i <= N; i++)
using namespace std;

int fallTime, moveNum;
vector<int> plumTreeFallPos;
vector<vector<int>> eachPlumNums;

void input(){
    cin >> fallTime >> moveNum;

    vector<int>(fallTime + 1).swap(plumTreeFallPos);
    FOR(i, fallTime)
        cin >> plumTreeFallPos[i];
}

int getNextPlumNums(const int& second, const int& moveCount){
    return eachPlumNums[second][moveCount] + (plumTreeFallPos[second + 1] == (1 + moveCount % 2));
}

void solve(){
    vector<vector<int>>(fallTime + 1, vector<int>(moveNum + 1, 0)).swap(eachPlumNums);
    FOR(i, fallTime){
        eachPlumNums[i][0] = getNextPlumNums(i - 1, 0);
        FOR(j, min(i, moveNum)){
            eachPlumNums[i][j] = max(getNextPlumNums(i - 1, j), getNextPlumNums(i - 1, j - 1));
        }
    }
}

void output(){
    cout << *max_element(eachPlumNums[fallTime].begin(), eachPlumNums[fallTime].end());
}

int main(){
    input ();
    solve ();
    output();
}