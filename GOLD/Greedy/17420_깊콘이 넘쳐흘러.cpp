#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i, N) for (int i = 0; i < N; i++)
#define DEADLINE first
#define AFTERDAY second
using namespace std;
typedef pair<long long, long long> gifticon;

const long long deadlineExtension = 30;
int gifticonNum;
vector<gifticon> gifticons;

long long deadlineExtensionCount = 0;

bool comp(const gifticon& a, const gifticon& b){
    return a.AFTERDAY != b.AFTERDAY ? a.AFTERDAY < b.AFTERDAY : a.DEADLINE < b.DEADLINE;
}

void input(){
    cin >> gifticonNum;
    vector<gifticon>(gifticonNum).swap(gifticons);
    gifticon nowGiftigon;
    FOR(i, gifticonNum) cin >> gifticons[i].DEADLINE;
    FOR(i, gifticonNum) cin >> gifticons[i].AFTERDAY;
}

void solve(){
    sort(gifticons.begin(), gifticons.end(), comp);
    long long prevDeadline = gifticons[0].AFTERDAY, nowDeadline = -1;
    FOR(i, gifticonNum){
        if (prevDeadline > gifticons[i].DEADLINE){
            prevDeadline = max(prevDeadline, gifticons[i].AFTERDAY);
            int extensionCount = (prevDeadline - gifticons[i].DEADLINE) / deadlineExtension;
            extensionCount += !!((prevDeadline - gifticons[i].DEADLINE) % deadlineExtension);
            gifticons[i].DEADLINE += extensionCount * deadlineExtension;
            deadlineExtensionCount += extensionCount;
        }

        nowDeadline = max(nowDeadline, gifticons[i].DEADLINE);

        if (i + 1 < gifticonNum && gifticons[i].AFTERDAY != gifticons[i + 1].AFTERDAY)
            prevDeadline = nowDeadline;
    }
}

void output(){
    cout << deadlineExtensionCount;
}

int main(){
    input ();
    solve ();
    output();
}