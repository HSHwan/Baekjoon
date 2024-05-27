#include <iostream>
#include <vector>

#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int blogDays, visitDuration;
vector<int> visitNums;
int visitMaxNum = 0, visitCount = 1;

void input(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> blogDays >> visitDuration;
    vector<int>(blogDays).swap(visitNums);
    FOR(i, blogDays) {
        cin >> visitNums[i];
    }
}

void setVisitMaxNum() {
    FOR(i, visitDuration) {
        visitMaxNum += visitNums[i];
    }
}

void solve(){
    setVisitMaxNum();
    int visitNum = visitMaxNum;
    for (int i = visitDuration; i < blogDays; i++) {
        visitNum += visitNums[i] - visitNums[i - visitDuration];
        if (visitNum > visitMaxNum) {
            visitMaxNum = visitNum;
            visitCount = 1;
        } else if (visitNum == visitMaxNum) {
            visitCount++;
        }
    }
}

void output(){
    if (visitMaxNum) {
        cout << visitMaxNum << '\n' << visitCount;
    } else {
        cout << "SAD";
    }
        
}

int main(){
    input ();
    solve ();
    output();
}