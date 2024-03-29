#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int pictureSize;
vector<string> picture;
int normalArea = 0, redGreenSameArea = 0;
vector<vector<bool>> pictureVisit;

void input(){
    cin >> pictureSize;

    vector<string>(pictureSize).swap(picture);
    FOR(i, pictureSize)
        cin >> picture[i];
}

bool isInPicture(const pair<int, int>& pos){
    if (pos.X >= pictureSize || pos.Y >= pictureSize || pos.X < 0 || pos.Y < 0)
        return false;
    return !pictureVisit[pos.X][pos.Y];
}

bool isSameColor(const char& prevColor, const char& nextColor, const bool& redGreenCheck){
    if (!redGreenCheck)
        return prevColor == nextColor;
    return (prevColor == nextColor) || (prevColor == 'R' && nextColor == 'G') || (prevColor == 'G' && nextColor == 'R');
}

void BFSPicture(const pair<int, int>& pos, const bool& redGreenCheck){
    pair<int, int> nowPos = pos;
    queue<pair<int, int>> nextPosQ;
    nextPosQ.push(nowPos);
    pictureVisit[nowPos.X][nowPos.Y] = true;
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    

    while (!nextPosQ.empty()){
        nowPos = nextPosQ.front();
        nextPosQ.pop();

        FOR(i, 4){
            pair<int, int> nextPos = {nowPos.X + dir[i].X, nowPos.Y + dir[i].Y};
            if (isInPicture(nextPos) && isSameColor(picture[nowPos.X][nowPos.Y], picture[nextPos.X][nextPos.Y], redGreenCheck)){
                nextPosQ.push(nextPos);
                pictureVisit[nextPos.X][nextPos.Y] = true;
            }
        }
    }
}



void solve(){
    vector<vector<bool>>(pictureSize, vector<bool>(pictureSize, false)).swap(pictureVisit);

    FOR(i, pictureSize){
        FOR(j, pictureSize){
            if (!pictureVisit[i][j]){
                BFSPicture({i, j}, false);
                normalArea++;
            } 
        }
    }

    vector<vector<bool>>(pictureSize, vector<bool>(pictureSize, false)).swap(pictureVisit);

    FOR(i, pictureSize){
        FOR(j, pictureSize){
            if (!pictureVisit[i][j]){
                BFSPicture({i, j}, true);
                redGreenSameArea++;
            } 
        }
    }
}

void output(){
    cout << normalArea << ' ' << redGreenSameArea;
}

int main(){
    input ();
    solve ();
    output();
}