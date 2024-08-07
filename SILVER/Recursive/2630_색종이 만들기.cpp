#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> coloredPaper;
int paperLen;
int whitePaperCount = 0, bluePaperCount = 0;

void input(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> paperLen;

    coloredPaper = vector<vector<int>>(paperLen, vector<int>(paperLen));
    FOR(i, paperLen) {
        FOR(j, paperLen) {
            cin >> coloredPaper[i][j];
        }
    }
}

bool isSameColor(pair<pii, int> paperInfo) {
    int paperColor = coloredPaper[paperInfo.first.X][paperInfo.first.Y];

    for (int i = paperInfo.first.X; i < paperInfo.first.X + paperInfo.second; i++) {
        for (int j = paperInfo.first.Y; j < paperInfo.first.Y + paperInfo.second; j++) {
            if (coloredPaper[i][j] != paperColor) {
                return false;
            }
        }
    }

    return true;
}

void solve(){
    queue<pair<pii, int>> papers;
    papers.push({{0, 0}, paperLen});

    pair<pii, int> nowPaper;
    while (!papers.empty()) {
        nowPaper = papers.front();
        papers.pop();

        if (isSameColor(nowPaper)) {
            whitePaperCount += !coloredPaper[nowPaper.first.X][nowPaper.first.Y];
            bluePaperCount += coloredPaper[nowPaper.first.X][nowPaper.first.Y];
        } else {
            int nextPaperLen = nowPaper.second / 2;
            papers.push({{nowPaper.first.X, nowPaper.first.Y}, nextPaperLen});
            papers.push({{nowPaper.first.X + nextPaperLen, nowPaper.first.Y}, nextPaperLen});
            papers.push({{nowPaper.first.X, nowPaper.first.Y + nextPaperLen}, nextPaperLen});
            papers.push({{nowPaper.first.X + nextPaperLen, nowPaper.first.Y + nextPaperLen}, nextPaperLen});
        }
        
    }
}

void output(){
    cout << whitePaperCount << '\n' << bluePaperCount;
}

int main(){
    input ();
    solve ();
    output();
}