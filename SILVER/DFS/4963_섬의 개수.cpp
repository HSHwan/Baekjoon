#include <iostream>
#include <vector>
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> map;
vector<vector<bool>> visited;
int w, h;
vector<pii> dirs = {{0, 1}, {1, 1}, {1, 0}, {-1, -1}, {0, -1}, {-1, 1}, {-1, 0}, {1, -1}};

bool isLand(pii pos) {
    if (pos.X >= 0 && pos.X < h && pos.Y >= 0 && pos.Y < w)
        return map[pos.X][pos.Y];
    return false;
}

void dfs(pii pos) {
    for (pii dir : dirs) {
        pii nextPos = {pos.X + dir.X, pos.Y + dir.Y};
        if (isLand(nextPos) && !visited[nextPos.X][nextPos.Y]) {
            visited[nextPos.X][nextPos.Y] = true;
            dfs(nextPos);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while (true) {
        cin >> w >> h;
        if (!w && !h)   break;
        vector<vector<int>>(h, vector<int>(w)).swap(map);
        vector<vector<bool>>(h, vector<bool>(w)).swap(visited);
        int landCount = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (!visited[i][j] && map[i][j]) {
                    visited[i][j] = true;
                    dfs({i, j});
                    landCount++;
                }
            }
        }

        cout << landCount << '\n';
    }
}