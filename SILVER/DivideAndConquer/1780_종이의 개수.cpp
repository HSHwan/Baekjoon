#include <iostream>
#define MAX 2187

using namespace std;

int colorPaper[MAX][MAX];
int minusPaperCount = 0, zeroPaperCount = 0, plusPaperCount = 0;

void checkColorPaper(int x, int y, int len) {
    int color = colorPaper[x][y];
    int xLen = x + len, yLen = y + len;
    for (int i = x; i < xLen; i++) {
        for (int j = y; j < yLen; j++) {
            if (colorPaper[i][j] != color) {
                int divLen = len / 3;
                checkColorPaper(x, y, divLen);
                checkColorPaper(x, y + divLen, divLen);
                checkColorPaper(x, y + 2 * divLen, divLen);
                checkColorPaper(x + divLen, y, divLen);
                checkColorPaper(x + divLen, y + divLen, divLen);
                checkColorPaper(x + divLen, y + 2 * divLen, divLen);
                checkColorPaper(x + 2 * divLen, y, divLen);
                checkColorPaper(x + 2 * divLen, y + divLen, divLen);
                checkColorPaper(x + 2 * divLen, y + 2 * divLen, divLen);
                return;
            }
        }
    }

    if (color == -1)
        minusPaperCount++;
    else if (color == 1)
        plusPaperCount++;
    else
        zeroPaperCount++;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int paperLen;
    cin >> paperLen;

    for (int i = 0; i < paperLen; i++) {
        for (int j = 0; j < paperLen; j++) {
            cin >> colorPaper[i][j];
        }
    }

    checkColorPaper(0, 0, paperLen);

    cout << minusPaperCount << '\n' << zeroPaperCount << '\n' << plusPaperCount;
}