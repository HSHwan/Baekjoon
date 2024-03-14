#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int testRoom, majorNum, minorNum;
unsigned long long viewerCount = 0;
vector<int> testTakers;

void input(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> testRoom;
    vector<int>(testRoom, 0).swap(testTakers);

    FOR(i, testRoom){
        cin >> testTakers[i];
    }
    cin >> majorNum >> minorNum;
}

void solve(){
    viewerCount = testRoom;
    for (const int& testTaker : testTakers){
        int restTestTaker = testTaker - majorNum;
        viewerCount += (restTestTaker > 0 ? restTestTaker / minorNum + !!(restTestTaker % minorNum) : 0);
    }
}

void output(){
    cout << viewerCount;
}

int main(){
    input ();
    solve ();
    output();
}