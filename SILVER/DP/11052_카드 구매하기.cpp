#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i, N) for (int i = 1; i <= N; i++)
using namespace std;

int cardPackNum;
vector<int> cardPacks;

void input(){
    cin >> cardPackNum;
    cardPacks = vector<int>(cardPackNum + 1);
    FOR(i, cardPackNum) {
        cin >> cardPacks[i];
    }
}

void solve(){
    FOR(i, cardPackNum) {
        FOR(j, i - 1) {
            cardPacks[i] = max(cardPacks[i], cardPacks[i - j] + cardPacks[j]);
        }
    }
}

void output(){
    cout << cardPacks[cardPackNum];
}

int main(){
    input ();
    solve ();
    output();
}