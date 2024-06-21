#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>

#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int opNum;
deque<int> ops;
int solveAvg = 0;

void input(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> opNum;
    ops = deque<int>(opNum);
    FOR(i, opNum) {
        cin >> ops[i];
    }
}

void cutOpinions(const int& cutNum) {
    FOR(i, cutNum) {
        ops.pop_front();
        ops.pop_back();
    }
}

void trimOpinions() {
    sort(ops.begin(), ops.end());

    int cutLine = round(opNum * 0.15);
    cutOpinions(cutLine);
}

int getOpinionAvg() {
    int opSum = 0;
    for (const int& op : ops) {
        opSum += op;
    }
    return round((float)opSum / ops.size());
}

void solve(){
    if (!opNum) return;
    trimOpinions();
    solveAvg = getOpinionAvg();
}

void output(){
    cout << solveAvg;
}

int main(){
    input ();
    solve ();
    output();
}