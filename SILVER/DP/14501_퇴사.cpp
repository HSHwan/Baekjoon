#include <iostream>
#include <vector>
#define FOR(i, N) for (int i = 0; i < N; i++)
#define T first
#define P second
using namespace std;

int consultingNum, maxConsultPriceSum = 0;
vector<pair<int, int>> allConsultings;
vector<int> consultPriceSum;

void input(){
    cin >> consultingNum;
    vector<pair<int, int>>(consultingNum + 1, {0, 0}).swap(allConsultings);
    vector<int>(consultingNum + 1, 0).swap(consultPriceSum);
    FOR(i, consultingNum){
        cin >> allConsultings[i].T >> allConsultings[i].P;
    }
}

void solve(){
    int deadLine;
    for (int i = 0; i <= consultingNum; i++){
        consultPriceSum[i] = max(consultPriceSum[i], maxConsultPriceSum);
        if (i + allConsultings[i].T <= consultingNum)
            consultPriceSum[i + allConsultings[i].T] = max(consultPriceSum[i + allConsultings[i].T], consultPriceSum[i] + allConsultings[i].P);
        maxConsultPriceSum = max(maxConsultPriceSum, consultPriceSum[i]);
    }
}

void output(){
    cout << maxConsultPriceSum;
}

int main(){
    input ();
    solve ();
    output();
}