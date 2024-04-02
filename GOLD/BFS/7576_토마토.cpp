#include <iostream>
#include <vector>
#include <queue>

#define X first
#define Y second
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;
typedef pair<int, int> pii;

vector<vector<int>> tomatoBox;
queue<pii> ripenTomatoes;
int boxRow, boxColumn;
int ripeDay = 0;

void input(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> boxColumn >> boxRow;

    vector<vector<int>>(boxRow, vector<int>(boxColumn)).swap(tomatoBox);
    FOR(i, boxRow){
        FOR(j, boxColumn)
            cin >> tomatoBox[i][j];
    }
}

bool isThereTomatoInTheBox(const vector<vector<int>>& box, const pii& pos){
    if (pos.X >= boxRow || pos.Y >= boxColumn || pos.X < 0 || pos.Y < 0)
        return false;
    return !box[pos.X][pos.Y];
}

bool isThereUnripenTomato(){
    FOR(i, boxRow){
        FOR(j, boxColumn){
            if (!tomatoBox[i][j])   return true;
        }
    }
    return false;
}

void getRipenAfterTomorrow(const pii& pos){
    vector<pii> posDir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    FOR(i, 4){
        pii nextPos = {pos.X + posDir[i].X, pos.Y + posDir[i].Y};
        if (isThereTomatoInTheBox(tomatoBox, nextPos)){
            tomatoBox[nextPos.X][nextPos.Y] = 1;
            ripenTomatoes.push(nextPos);
        }
    }
}

void solve(){
    FOR(i, boxRow){
        FOR(j, boxColumn){
            if (tomatoBox[i][j] == 1){
                ripenTomatoes.push({i, j});
            }
        }
    }

    while (!ripenTomatoes.empty()) {
        int ripenTomatoNum = ripenTomatoes.size();
        FOR(i, ripenTomatoNum){
            pii nowTomato = ripenTomatoes.front();
            ripenTomatoes.pop();
            getRipenAfterTomorrow(nowTomato);
        }
        ripeDay++;
    }
    if (isThereUnripenTomato()) ripeDay = -1;
    else    ripeDay--;
}

void output(){
    cout << ripeDay;
}

int main(){
    input ();
    solve ();
    output();
}