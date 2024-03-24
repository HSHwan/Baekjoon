#include <iostream>
#include <vector>
#define X first
#define Y second
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int houseRow, houseColumn;
int airTime;
vector<vector<int>> houseDust;
vector<pair<int, int>> airCleaner;

void input(){
    cin >> houseRow >> houseColumn >> airTime;
    vector<vector<int>>(houseRow, vector<int>(houseColumn)).swap(houseDust);

    FOR(i, houseRow){
        FOR(j, houseColumn){
            cin >> houseDust[i][j];
            if (houseDust[i][j] == -1)
                airCleaner.push_back({i, j});
        }
    }
}

bool isSpreadable(const pair<int, int>& pos){
    if (pos.X >= houseRow || pos.Y >= houseColumn || pos.X < 0 || pos.Y < 0)
        return false;
    return !(pos == airCleaner[0] || pos == airCleaner[1]);
}

void spreadDust(vector<vector<int>>& map, const pair<int, int>& pos, const int& posDust){
    vector<pair<int, int>> spreadDir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int spreadCount = 0;
    int spreadDustNum = posDust / 5;

    FOR(i, 4){
        pair<int, int> nextPos = {pos.X + spreadDir[i].X, pos.Y + spreadDir[i].Y};
        if (isSpreadable(nextPos)){
            map[nextPos.X][nextPos.Y] += spreadDustNum;
            spreadCount++;
        }
    }
    map[pos.X][pos.Y] += posDust - spreadCount * spreadDustNum;
}

void spreadDustAll(){
    vector<vector<int>> dustSpreaded(houseRow, vector<int>(houseColumn, 0));
    dustSpreaded[airCleaner[0].X][0] = -1;
    dustSpreaded[airCleaner[1].X][0] = -1;
    FOR(i, houseRow){
        FOR(j, houseColumn){
            if (houseDust[i][j] == -1 || !houseDust[i][j])
                continue;
            spreadDust(dustSpreaded, {i, j}, houseDust[i][j]);
        }
    }
    houseDust = dustSpreaded;
}

void circulateDust(){
    // circulate counterClockWise
    FOR(i, airCleaner[0].X - 1)
        houseDust[i + 1][0] = houseDust[i][0];
    FOR(i, houseColumn - 1)
        houseDust[0][i] = houseDust[0][i + 1];
    FOR(i, airCleaner[0].X)
        houseDust[i][houseColumn - 1] = houseDust[i + 1][houseColumn - 1];
    for (int i = houseColumn - 1; i > 1; i--)
        houseDust[airCleaner[0].X][i] = houseDust[airCleaner[0].X][i - 1];
    houseDust[airCleaner[0].X][1] = 0;

    // circulate clockWise
    for (int i = airCleaner[1].X + 1; i < houseRow - 1; i++)
        houseDust[i][0] = houseDust[i + 1][0];
    FOR(i, houseColumn - 1)
        houseDust[houseRow - 1][i] = houseDust[houseRow - 1][i + 1];
    for (int i = houseRow - 1; i > airCleaner[1].X; i--)
        houseDust[i][houseColumn - 1] = houseDust[i - 1][houseColumn - 1];
    for (int i = houseColumn - 1; i > 1; i--)
        houseDust[airCleaner[1].X][i] = houseDust[airCleaner[1].X][i - 1];
    houseDust[airCleaner[1].X][1] = 0;
}

void solve(){
    FOR(i, airTime){
        spreadDustAll();
        circulateDust();
    }
}

void output(){
    int dustSum = 0;

    FOR(i, houseRow){
        FOR(j, houseColumn){
            if (houseDust[i][j] != -1)
                dustSum += houseDust[i][j];
        }
    }
    cout << dustSum;
}

int main(){
    input ();
    solve ();
    output();
}