#include <iostream>
#include <vector>
#include <map>
#include <string>

#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;
char nowGame;
int gameNeedPeople;
int playerNum, actualPlayerNum = 0;
int gameNum = 0;
string gameTypes = "YFO";
vector<string> players;
map<string, bool> playerCheck;

void input(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> playerNum >> nowGame;

    vector<string>(playerNum).swap(players);
    FOR(i, playerNum)
        cin >> players[i];
}

void solve(){
    gameNeedPeople = 1 + gameTypes.find(nowGame);
    FOR(i, playerNum){
        if (!playerCheck.count(players[i])){
            playerCheck[players[i]] = true;
            actualPlayerNum++;
        }
    }
    gameNum = actualPlayerNum / gameNeedPeople;
}

void output(){
    cout << gameNum;
}

int main(){
    input ();
    solve ();
    output();
}