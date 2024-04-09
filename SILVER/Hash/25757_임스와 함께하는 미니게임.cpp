#include <iostream>
#include <vector>
#include <map>
#include <string>

#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;
int gameType;
int playerNum, actualPlayerNum = 0;
string gameTypes = "YFO";
vector<string> players;
map<string, bool> playerCheck;

void input(){
    char nowGame;
    cin >> playerNum >> nowGame;

    vector<string>(playerNum).swap(players);
    FOR(i, playerNum)
        cin >> players[i];
}

void solve(){

}

void output(){

}

int main(){
    input ();
    solve ();
    output();
}