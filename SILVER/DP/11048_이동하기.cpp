#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

vector<vector<int>> mazeCandy;
int rowNum, columnNum;

void input(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> rowNum >> columnNum;
    mazeCandy = vector<vector<int>>(rowNum, vector<int>(columnNum, 0));
    FOR(i, rowNum) {
        FOR(j, columnNum) {
            cin >> mazeCandy[i][j];
        }
    }
}

void trimSetting() {
    FOR(i, rowNum - 1) {
        mazeCandy[i + 1][0] += mazeCandy[i][0];
    }
    FOR(i, columnNum - 1) {
        mazeCandy[0][i + 1] += mazeCandy[0][i];
    }
}

int getPreviousMaxCandy(int row, int col) {
    return max(max(mazeCandy[row - 1][col], mazeCandy[row][col - 1]), mazeCandy[row - 1][col - 1]);
}

void solve(){
    trimSetting();
    for (int i = 1; i < rowNum; i++) {
        for (int j = 1; j < columnNum; j++) {
            mazeCandy[i][j] += getPreviousMaxCandy(i, j);
        }
    }
}

void output(){
    cout << mazeCandy[rowNum - 1][columnNum - 1];
}

int main(){
    input ();
    solve ();
    output();
}