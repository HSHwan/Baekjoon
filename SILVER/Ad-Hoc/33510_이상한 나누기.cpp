#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    
    int digit;
    string binaryNum;
    cin >> digit >> binaryNum;

    int oddCount = 0;

    for (int i = digit - 1; i > 0; i--) {
        if (binaryNum[i] == '1') {
            for (int j = i - 1; j > 0; j--) {
                if (binaryNum[j] == '0')
                    oddCount++;
            }
            oddCount++;
            break;
        }
    }

    cout << oddCount;
}