#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

typedef pair<int, int> pii;

int mapLen, landNum = 1;
vector<vector<int>> map;
vector<pii> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool isOnMap(pii pos) {
    return (pos.X >= 0 && pos.X < mapLen && pos.Y >= 0 && pos.Y < mapLen);
}

void checkLand(pii pos) {
    queue<pii> posQ;
    posQ.push(pos);
    map[pos.X][pos.Y] = -landNum;

    while (!posQ.empty()) {
        pii nowPos = posQ.front();
        posQ.pop();

        for (pii dir : dirs) {
            pii nextPos = {nowPos.X + dir.X, nowPos.Y + dir.Y};
            if (isOnMap(nextPos) && map[nextPos.X][nextPos.Y] == 1) {
                map[nextPos.X][nextPos.Y] = -landNum;
                posQ.push(nextPos);
            }
        }
    }
}

int solveShortestBridgeLen(int landNum) {
    queue<pair<pii, int>> landQ;
    vector<vector<bool>> visited(mapLen, vector<bool>(mapLen, false));

    for (int i = 0; i < mapLen; i++) {
        for (int j = 0; j < mapLen; j++) {
            if (map[i][j] == -landNum) {
                for (pii dir : dirs) {
                    pii nextPos = {i + dir.X, j + dir.Y};
                    if (isOnMap(nextPos) && !map[nextPos.X][nextPos.Y]) {
                        landQ.push({{i, j}, -1});
                        visited[i][j] = true;
                        break;
                    }
                }
            }
        }
    }

    while (!landQ.empty()) {
        pair<pii, int> now = landQ.front();
        pii nowPos = now.first;
        int dist = now.second;
        landQ.pop();

        if (map[nowPos.X][nowPos.Y] < 0 && map[nowPos.X][nowPos.Y] != -landNum)
            return dist;

        for (pii dir : dirs) {
            pii nextPos = {nowPos.X + dir.X, nowPos.Y + dir.Y};
            if (!isOnMap(nextPos) || visited[nextPos.X][nextPos.Y]) continue;
            if (map[nextPos.X][nextPos.Y] != -landNum) {
                visited[nextPos.X][nextPos.Y] = true;
                landQ.push({nextPos, dist + 1});
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> mapLen;
    map.resize(mapLen, vector<int>(mapLen));
    for (int i = 0; i < mapLen; i++) {
        for (int j = 0; j < mapLen; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < mapLen; i++) {
        for (int j = 0; j < mapLen; j++) {
            if (map[i][j] == 1) {
                checkLand({i, j});
                landNum++;
            }
        }
    }

    int bridgeLen = mapLen * mapLen;
    for (int i = 1; i < landNum; i++) {
        bridgeLen = min(solveShortestBridgeLen(i), bridgeLen);
        if (bridgeLen == 1)
            break;
    }

    cout << bridgeLen;
}