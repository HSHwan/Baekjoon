#include <iostream>
#include <vector>
#define X first
#define Y second

#define MAX 1000

using namespace std;

typedef pair<int, int> pii;

int row, column;
vector<vector<int>> rollerCoaster;

string moveAllCells(char startDir, char nextDir, char revDir, int len, int repCount) {
    string move;
    for (int i = 0; i < repCount; i++) {
        for (int i = 0; i < len; i++)
            move.push_back(startDir);
        move.push_back(nextDir);
        for (int j = 0; j < len; j++) 
            move.push_back(revDir);
        move.push_back(nextDir);
    }
    for (int j = 0; j < len; j++) 
        move.push_back(startDir);
    return move;
}

string findRollerCoasterMove(pii exceptPos) {
    string rollerCoasterMove;
    pii nowPos = {0, 0};
    int nearX = exceptPos.X - (exceptPos.X % 2);
    while (nowPos.X < nearX) {
        for (int j = 0; j < column - 1; j++) {
            rollerCoasterMove.push_back('R');
        }
        rollerCoasterMove.push_back('D');
        for (int j = 0; j < column - 1; j++) {
            rollerCoasterMove.push_back('L');
        }
        rollerCoasterMove.push_back('D');
        nowPos.X += 2;
    }

    bool flag = true;
    while (nowPos.Y < column) {
        if (nowPos.Y != exceptPos.Y) {
            if (flag) {
                rollerCoasterMove.push_back('D');
                flag = false;
            }
            else {
                rollerCoasterMove.push_back('U');
                flag = true;
            }
        }

        if (nowPos.Y != column - 1) {
            rollerCoasterMove.push_back('R');
        }
        nowPos.Y++;
    }
    nowPos.X += 2;
    if (nowPos.X < row) {
        rollerCoasterMove.push_back('D');
    }

    while (nowPos.X < row) {
        for (int i = 0; i < column - 1; i++) {
            rollerCoasterMove.push_back('L');
        }
        rollerCoasterMove.push_back('D');
        for (int i = 0; i < column - 1; i++) {
            rollerCoasterMove.push_back('R');
        }
        nowPos.X += 2;

        if (nowPos.X < row) {
            rollerCoasterMove.push_back('D');
        }
    }

    return rollerCoasterMove;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> row >> column;

    pii minPos;
    int minHappy = MAX;
    rollerCoaster.resize(row, vector<int>(column));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> rollerCoaster[i][j];
            if ((i + j) % 2 && rollerCoaster[i][j] < minHappy) {
                minPos = {i, j};
                minHappy = rollerCoaster[i][j];
            }
        }
    }

    if (row % 2) {
        string move = moveAllCells('R', 'D', 'L', column - 1, row / 2);
        cout << move;
    }
    else if (column % 2) {
        string move = moveAllCells('D', 'R', 'U', row - 1, column / 2);
        cout << move;
    }
    else {
        string move = findRollerCoasterMove(minPos);
        cout << move;
    }
}