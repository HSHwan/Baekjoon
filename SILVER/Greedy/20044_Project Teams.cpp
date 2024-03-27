#include <iostream>
#include <vector>
#include <algorithm>

#define INF (~0U >> 2)
#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int studentTeamNum;
int minStudentTeamAbility = INF;
vector<int> studentAbility;

void input(){
    cin >> studentTeamNum;
    vector<int>(studentTeamNum * 2).swap(studentAbility);

    FOR(i, studentTeamNum * 2)
        cin >> studentAbility[i];
}

void solve(){
    sort(studentAbility.begin(), studentAbility.end());
    FOR(i, studentTeamNum){
        minStudentTeamAbility = min(minStudentTeamAbility, studentAbility[i] + studentAbility[studentTeamNum * 2 - 1 - i]);
    }
}

void output(){
    cout << minStudentTeamAbility;
}

int main(){
    input ();
    solve ();
    output();
}