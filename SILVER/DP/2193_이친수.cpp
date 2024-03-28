#include <iostream>
#include <vector>
#define ZERO first
#define ONE second
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int N;
vector<pair<long long, long long>> pinaryNumbers;
void input(){
    cin >> N;
}

void solve(){
    vector<pair<long long, long long>>(N + 1).swap(pinaryNumbers);
    pinaryNumbers[1] = {0, 1};

    for (int i = 2; i <= N; i++){
        pinaryNumbers[i].ZERO = pinaryNumbers[i - 1].ZERO + pinaryNumbers[i - 1].ONE;
        pinaryNumbers[i].ONE = pinaryNumbers[i - 1].ZERO;
    }
}

void output(){
    cout << pinaryNumbers[N].ZERO + pinaryNumbers[N].ONE;
}

int main(){
    input ();
    solve ();
    output();
}