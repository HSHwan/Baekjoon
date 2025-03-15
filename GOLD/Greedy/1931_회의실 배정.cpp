#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FOR(i, N) for(int i = 0; i < N; i++)

int N, meetingCount = 0;
vector<vector<int>> meetings;

void input(){
    cin >> N;
    vector<vector<int>>(N, vector<int>(2, 0)).swap(meetings);
    FOR(i, N)
        cin >> meetings[i][0] >> meetings[i][1];
}

bool comp(const vector<int>& a, const vector<int>& b){
    return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
}

void solve(){
    sort(meetings.begin(), meetings.end(), comp);
    vector<int> nowMeeting(2, 0);
    FOR(i, N){
        if (nowMeeting[1] <= meetings[i][0]){
            meetingCount++;
            nowMeeting = meetings[i];
        }
        else if (nowMeeting[1] > meetings[i][1]){
            nowMeeting = meetings[i];
        }
    }
}

void output(){
    cout << meetingCount;
}

int main(){
    input ();
    solve ();
    output();
}