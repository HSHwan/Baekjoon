#include <iostream>
#include <vector>

#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int beltLen, beltNoSpaceNum;
int beltNoSpaceCount = 0;
int stepCount = 0;
vector<int> conveyorBelt;
vector<bool> beltSpaceRobotCheck;

void input(){
    cin >> beltLen >> beltNoSpaceNum;
    vector<int>(2 * beltLen).swap(conveyorBelt);
    FOR(i, 2 * beltLen)
        cin >> conveyorBelt[i];
}

void countNoSpace(const int& pos){
    beltNoSpaceCount += !conveyorBelt[pos];
}

void moveRobot(const int& pos){
    int nextPos = (pos + 1) % (2 * beltLen);

    if (!beltSpaceRobotCheck[nextPos] && conveyorBelt[nextPos]){
        beltSpaceRobotCheck[nextPos] = true;
        if (pos == -1)  beltSpaceRobotCheck.back() = false;
        else    beltSpaceRobotCheck[pos] = false;
        conveyorBelt[nextPos] -= 1;
        countNoSpace(nextPos);
    }
}

void rotateBelt(){
    FOR(i, 2 * beltLen){
        if (!beltSpaceRobotCheck[i])    continue;
        moveRobot(i);
    }
}

void putUpRobot(){
    moveRobot(-1);
}

void solve(){
    vector<bool>(2 * beltLen, false).swap(beltSpaceRobotCheck);
    while (beltNoSpaceCount < beltNoSpaceNum){
        rotateBelt();
        putUpRobot();
        stepCount++;
    }   
}

void output(){
    cout << stepCount;
}

int main(){
    input ();
    solve ();
    output();
}