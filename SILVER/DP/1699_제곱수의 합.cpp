#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;

    vector<int> squareNum(num + 1, 0), twoSquareNum(num + 1, 0);

    for (int i = 1; i * i <= num; i++) {
        squareNum[i * i] = 1;
        for (int j = i; i * i + j * j <= num; j++) {
            twoSquareNum[i * i + j * j] = 1; 
        }
    }

    if (squareNum[num]) {
        cout << 1;
    }
    else if (twoSquareNum[num]) {
        cout << 2;
    }
    else {
        for (int i = 1; i * i <= num; i++) {
            if (twoSquareNum[num - i * i]) {
                cout << 3;
                return 0;
            }
        }

        cout << 4;
    }
}