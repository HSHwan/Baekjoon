#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

vector<string> houseMap;
vector<int> houseAreaList;
int mapLen;

void input(){
    cin >> mapLen;
    vector<string>(mapLen).swap(houseMap);
    
    FOR(i, mapLen) {
        cin >> houseMap[i];
    }
}

bool isThereHouse(vector<int> pos) {
    if (pos[0] >= mapLen || pos[1] >= mapLen || pos[0] < 0 || pos[1] < 0)
        return false;
    return houseMap[pos[0]][pos[1]] == '1';
}

int searchHouseArea(vector<int> pos) {
    queue<vector<int>> posQ;
    posQ.push(pos);
    houseMap[pos[0]][pos[1]] = '0';
    int houseNum = 1;
    
    vector<int> nowPos, nextPos;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!posQ.empty()) {
        nowPos = posQ.front();
        posQ.pop();
    
        for (const vector<int>& dir : dirs) {
            nextPos = {nowPos[0] + dir[0], nowPos[1] + dir[1]};
            if (isThereHouse(nextPos)) {
                posQ.push(nextPos);
                houseMap[nextPos[0]][nextPos[1]] = '0';
                houseNum++;
            }
        }
    }

    return houseNum;
}

void solve(){
    FOR(i, mapLen) {
        FOR(j, mapLen) {
            if (houseMap[i][j] == '1') {
                houseAreaList.push_back(searchHouseArea({i, j}));
            }
        }
    }

    sort(houseAreaList.begin(), houseAreaList.end());
}

void output(){
    cout << houseAreaList.size() << '\n';
    for (const int& house : houseAreaList) {
        cout << house << '\n';
    }
}

int main(){
    input ();
    solve ();
    output();
}