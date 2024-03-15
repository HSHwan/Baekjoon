#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF (~0U >> 2)
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int peopleNum, synergyDiff = INF;
vector<vector<int>> synergies;

void input(){
    cin >> peopleNum;
    vector<vector<int>>(peopleNum, vector<int>(peopleNum)).swap(synergies);

    FOR(i, peopleNum){
        FOR(j, peopleNum){
            cin >> synergies[i][j];
        }
    }
}

int getSynergy(const vector<int>& v){
    int synergySum = 0;
    FOR (i, v.size()){
        for (int j = i + 1; j < v.size(); j++){
            synergySum += synergies[v[i]][v[j]] + synergies[v[j]][v[i]];
        }
    }
    return synergySum;
}

void solve(){
    int teamNum = (1 << peopleNum) - (1 << (peopleNum / 2));
    for (int i = (1 << (peopleNum / 2) - 1); i <= teamNum / 2; i++){
        vector<int> start, link;
        if (__builtin_popcount(i) == peopleNum / 2){
            for (int j = 0; j < peopleNum; j++){
                if (i & (1 << j)){
                    start.push_back(j);
                }
                else {
                    link.push_back(j);
                }
            }
            synergyDiff = min(synergyDiff, abs(getSynergy(start) - getSynergy(link)));
        }
    }
}

void output(){
    cout << synergyDiff;
}

int main(){
    input ();
    solve ();
    output();
}
