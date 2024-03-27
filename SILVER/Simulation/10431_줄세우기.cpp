#include <iostream>
#include <vector>

#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int testCaseNum;
vector<int> testCaseResult(1);
vector<vector<int>> studentHeight;

void input(){
    cin >> testCaseNum;
    vector<vector<int>>(testCaseNum + 1, vector<int>(20)).swap(studentHeight);

    int testNum;
    FOR(i, testCaseNum){
        cin >> testNum;
        FOR(j, 20)
            cin >> studentHeight[testNum][j];
    }
}

void solve(){
    for (int i = 1; i <= testCaseNum; i++){
        int stepCount = 0;
        FOR(j, 20){
            for (int k = j - 1; k >= 0; k--)
                stepCount += studentHeight[i][j] < studentHeight[i][k];
        }
        testCaseResult.push_back(stepCount);
    }
}

void output(){
    for (int i = 1; i <= testCaseNum; i++)
        cout << i << ' ' << testCaseResult[i] << '\n';
}

int main(){
    input ();
    solve ();
    output();
}