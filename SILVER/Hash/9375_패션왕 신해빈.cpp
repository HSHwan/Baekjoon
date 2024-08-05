#include <iostream>
#include <map>
#include <string>

#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

map<string, int> dressCount;
int dressCase;

void input(){
    int dressNum;

    cin >> dressNum;

    string dressName, dressType;
    FOR(i, dressNum) {
        cin >> dressName >> dressType;

        if (!dressCount.count(dressType)) {
            dressCount[dressType] = 0;
        }

        dressCount[dressType]++;
    }

}

void solve(){
    dressCase = 1;

    for (auto it = dressCount.begin(); it != dressCount.end(); it++) {
        dressCase *= (it->second + 1);
    }

    dressCase--;
}

void output(){
    cout << dressCase << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int testcase;
    cin >> testcase;
    FOR(i, testcase) {
        dressCount.clear();
        input ();
        solve ();
        output();
    }
    
}