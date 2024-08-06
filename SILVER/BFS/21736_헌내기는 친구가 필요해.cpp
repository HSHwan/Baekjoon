#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define X first
#define Y second
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

vector<vector<char>> campus;
pair<int, int> startPos;
int campusRow, campusColumn;
int peopleCount = 0;

void input(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> campusRow >> campusColumn;
    campus = vector<vector<char>>(campusRow, vector<char>(campusColumn));

    string campusInfo;
    FOR(i, campusRow) {
        cin >> campusInfo;
        FOR (j, campusColumn) {
            campus[i][j] = campusInfo[j];
        }
    }
}

void checkStartPosition() {
    FOR(i, campusRow) {
        FOR(j, campusColumn) {
            if (campus[i][j] == 'I') {
                startPos = {i, j};
                return;
            }
        }
    }
}

bool isMovable(pair<int, int> pos) {
    if (pos.X >= campusRow || pos.Y >= campusColumn || pos.X < 0 || pos.Y < 0)
        return false;
    return campus[pos.X][pos.Y] != 'X';
}

void searchCampusPeople() {
    vector<vector<bool>> visited(campusRow, vector<bool>(campusColumn, false));
    queue<pair<int, int>> posQ;
    posQ.push(startPos);
    visited[startPos.X][startPos.Y] = true;

    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    pair<int, int> nowPos, nextPos;
    while(!posQ.empty()) {
        nowPos = posQ.front();
        posQ.pop();
        
        for (pair<int, int> dir : dirs) {
            nextPos = {nowPos.X + dir.X, nowPos.Y + dir.Y};
            if (isMovable(nextPos) && !visited[nextPos.X][nextPos.Y]) {
                posQ.push(nextPos);
                visited[nextPos.X][nextPos.Y] = true;
                peopleCount += campus[nextPos.X][nextPos.Y] == 'P';
            }
        }
    }
}

void solve(){
    checkStartPosition();
    searchCampusPeople();
}

void output(){
    if (!peopleCount) {
        cout << "TT";
        return;
    }

    cout << peopleCount;
}

int main(){
    input ();
    solve ();
    output();
}