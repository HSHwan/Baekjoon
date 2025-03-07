#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

typedef pair<int, int> pii;

int row, column;
vector<vector<int>> maze;
vector<vector<bool>> visited;
vector<pii> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool isMovable(pii pos) {
    if (pos.X >= 0 && pos.X < row && pos.Y >= 0 && pos.Y < column)
        return maze[pos.X][pos.Y];
    return false;
}

int bfs(pii pos) {
    pii nowPos = pos;
    queue<pii> posQ;
    posQ.push(nowPos);
    visited[nowPos.X][nowPos.Y] = true;
    vector<vector<int>> moveCount(row, vector<int>(column, row * column));
    moveCount[nowPos.X][nowPos.Y] = 1;

    while (!posQ.empty()) {
        nowPos = posQ.front();
        posQ.pop();
        if (nowPos.X == row - 1 && nowPos.Y == column - 1)
            return moveCount[nowPos.X][nowPos.Y];

        for (pii dir : dirs) {
            pii nextPos = {nowPos.X + dir.X, nowPos.Y + dir.Y};
            if (isMovable(nextPos) && !visited[nextPos.X][nextPos.Y]) {
                moveCount[nextPos.X][nextPos.Y] = moveCount[nowPos.X][nowPos.Y] + 1;
                posQ.push(nextPos);
                visited[nextPos.X][nextPos.Y] = true;
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> row >> column;
    maze.resize(row, vector<int>(column));
    visited.assign(row, vector<bool>(column, false));

    string oneRow;
    for (int i = 0; i < row; i++) {
        cin >> oneRow;
        for (int j = 0; j < column; j++) {
            maze[i][j] = oneRow[j] - '0';
        }
    }

    int minMoveCount = bfs({0, 0});
    cout << minMoveCount;
}