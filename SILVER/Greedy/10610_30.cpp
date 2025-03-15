#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string num;
    cin >> num;

    int numCount[10] = {0, };
    
    int sum = 0;
    for (char digit : num) {
        int digitNum = digit - '0';
        numCount[digitNum]++;
        sum += digitNum;
    }
    if (sum % 3 == 0 && numCount[0]) {
        string newNum;
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < numCount[i]; j++) {
                newNum.push_back(i + '0');
            }
        }
        cout << newNum;
    }
    else
        cout << -1;
}