#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

const int MEDAL = 3;
int nationNum, targetNationNum;
int targetNationRank = 1;
vector<vector<int>> nations;

bool isBetter(const vector<int>& a, const vector<int>& b){
    for (int i = 1; i <= MEDAL; i++){
        if (a[i] != b[i])
            return a[i] > b[i];
    }
    return a.back() > b.back();
}

void input(){
    cin >> nationNum >> targetNationNum;
    vector<vector<int>>(nationNum, vector<int>(MEDAL + 1)).swap(nations);
    FOR(i, nationNum){
        cin >> nations[i][0] >> nations[i][1] >> nations[i][2] >> nations[i][3];
    }
}

vector<int> getTargetNation(){
    FOR(i, nationNum){
        if (nations[i][0] == targetNationNum)
            return nations[i];
    }
    return vector<int>(MEDAL + 1, 0);
}

void solve(){
    vector<int> targetNation = getTargetNation();

    FOR(i, nationNum){
        if (nations[i][0] == targetNationNum)   continue;
        if (isBetter(nations[i], targetNation)) targetNationRank++;
    }
}

void output(){
    cout << targetNationRank;
}

int main(){
    input ();
    solve ();
    output();
}