#include <iostream>
#include <vector>

#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

const int RATE = 31;
const int MODULAR = 1234567891;
vector<unsigned long long> rateList = { 1 };

int hashStrLen;
string hashStr;
unsigned long long hashValue = 0;

void input(){
    cin >> hashStrLen >> hashStr;
}

void setRateList(int len) {
    FOR(i, len - 1) {
        rateList.push_back((rateList.back() * RATE) % MODULAR);
    }
}

void solve(){
    setRateList(hashStrLen);
    FOR(i, hashStrLen) {
        hashValue += (rateList[i] * (hashStr[i] - 'a' + 1)) % MODULAR;
        hashValue %= MODULAR;
    }
}

void output(){
    cout << hashValue;
}

int main(){
    input ();
    solve ();
    output();
}