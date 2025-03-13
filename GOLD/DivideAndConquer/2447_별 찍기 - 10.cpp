#include <iostream>

#define MAX 2187
using namespace std;

char buffer[MAX][MAX];

void printStar(int x, int y, int n, char chr) {
    if (n == 1) {        
        buffer[x][y] = chr;
        return;
    }

    int divN = n / 3;
    printStar(x, y, divN, chr);
    printStar(x, y + divN, divN, chr);
    printStar(x, y + 2 * divN, divN, chr);
    printStar(x + divN, y, divN, chr);
    printStar(x + divN, y + divN, divN, ' ');
    printStar(x + divN, y + 2 * divN, divN, chr);
    printStar(x + 2 * divN, y, divN, chr);
    printStar(x + 2 * divN, y + divN, divN, chr);
    printStar(x + 2 * divN, y + 2 * divN, divN, chr);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int starLen;
    cin >> starLen;

    printStar(0, 0, starLen, '*');
    for (int i = 0; i < starLen; i++) {
        for (int j = 0; j < starLen; j++) {
            cout << buffer[i][j];
        }
        cout << '\n';
    }
}