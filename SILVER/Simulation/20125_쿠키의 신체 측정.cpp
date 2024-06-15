#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int boardLen;
vector<vector<char>> board;
pair<int, int> heartPos;
pair<int, int> waistEndPos;
vector<int> allSize;

void input(){
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> boardLen;
    board = vector<vector<char>>(boardLen, vector<char>(boardLen));
    FOR(i, boardLen) {
        FOR(j, boardLen) {
            cin >> board[i][j];
        }
    }
}

void checkHeartPos() {
    FOR(i, boardLen) {
        int headYPos = find(board[i].begin(), board[i].end(), '*') - board[i].begin();
        if (headYPos < boardLen) {
            heartPos = {i + 1, headYPos};
            break;
        }
    }
}

void checkArmLength() {
    // Check Left Arm Length
    int leftLen = 0;
    for (int i = heartPos.Y - 1; i >= 0; i--) {
        if (board[heartPos.X][i] != '*')    break;
        leftLen++;
    }

    // Check Right Arm Length
    int rightLen = 0;
    for (int i = heartPos.Y + 1; i < boardLen; i++) {
        if (board[heartPos.X][i] != '*')    break;
        rightLen++;
    }

    // Save Result
    allSize.push_back(leftLen);
    allSize.push_back(rightLen);
}

void checkWaistLength() {
    // Check Waist Length
    int waistLen = 0;
    for (int i = heartPos.X + 1; i < boardLen; i++) {
        if (board[i][heartPos.Y] != '*') {
            waistEndPos = {i - 1, heartPos.Y};
            break;
        }
        waistLen++;
    }

    // Save Result
    allSize.push_back(waistLen);
}

void checkLegLength() {
    // Check Left Leg Length
    int leftLen = 0;
    for (int i = waistEndPos.X + 1; i < boardLen; i++) {
        if (board[i][waistEndPos.Y - 1] != '*')    break;
        leftLen++;
    }

    // Check Right Leg Length
    int rightLen = 0;
    for (int i = waistEndPos.X + 1; i < boardLen; i++) {
        if (board[i][waistEndPos.Y + 1] != '*')    break;
        rightLen++;
    }

    // Save Result
    allSize.push_back(leftLen);
    allSize.push_back(rightLen);
}

void solve(){
    checkHeartPos();
    checkArmLength();
    checkWaistLength();
    checkLegLength();
}

void output(){
    cout << heartPos.X + 1 << ' ' << heartPos.Y + 1 << '\n';
    for (int size : allSize) {
        cout << size << ' ';
    }
}

int main(){
    input ();
    solve ();
    output();
}