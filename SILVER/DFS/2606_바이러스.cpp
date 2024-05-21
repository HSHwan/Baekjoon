#include <iostream>
#include <vector>

#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

vector<vector<int>> network;
vector<bool> visitTable;
int computerNum;
int connectNum;
int infectedComputerNum = 0;

void input(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> computerNum >> connectNum;
    network = vector<vector<int>>(computerNum + 1);

    int com1, com2;
    FOR(i, connectNum) {
        cin >> com1 >> com2;
        network[com1].push_back(com2);
        network[com2].push_back(com1);
    }
}

void setVisitTable() {
    visitTable = vector<bool>(computerNum + 1, false);
    visitTable[1] = true;
}

void trackInfection(int com) {
    for (int infectCom : network[com]) {
        if (!visitTable[infectCom]) {
            visitTable[infectCom] = true;
            infectedComputerNum++;
            trackInfection(infectCom);
        }
    }
}

void solve(){
    setVisitTable();
    trackInfection(1);
}

void output(){
    cout << infectedComputerNum;
}

int main(){
    input ();
    solve ();
    output();
}