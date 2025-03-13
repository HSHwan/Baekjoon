#include <iostream>

#define MAX 64
using namespace std;

char video[MAX][MAX];

string compressVideo(int x, int y, int len) {
    char dot = video[x][y];

    int xLen = x + len, yLen = y + len;

    for (int i = x; i < xLen; i++) {
        for (int j = y; j < yLen; j++) {
            if (video[i][j] != dot) {
                string result = "(";
                int divLen = len / 2;
                result.append(compressVideo(x, y, divLen));
                result.append(compressVideo(x, y + divLen, divLen));
                result.append(compressVideo(x + divLen, y, divLen));
                result.append(compressVideo(x + divLen, y + divLen, divLen));
                result.push_back(')');
                return result;
            }
        }
    }
    return to_string(dot - '0');
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int videoLen;
    cin >> videoLen;

    for (int i = 0; i < videoLen; i++) {
        cin >> video[i];
    }

    string compressedVideo = compressVideo(0, 0, videoLen);
    cout << compressedVideo;
}