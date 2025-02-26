#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getStickers(int n) {
    vector<vector<int>> stickers(2, vector<int>(n, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> stickers[i][j];
        }
    }
    
    return stickers;
}

int solveStickerMaxSum(int n, vector<vector<int>> stickers) {
    vector<vector<int>> stickerSum = stickers;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            stickerSum[j][i] += max(stickerSum[j][i - 1] - stickers[j][i - 1], stickerSum[1 - j][i - 1]);
        }
    }

    return max(stickerSum[0][n - 1], stickerSum[1][n - 1]);
}

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL);

    int testcase;
    cin >> testcase;

    while (testcase--) {
        int n;
        cin >> n;

        vector<vector<int>> stickers = getStickers(n);
        cout << solveStickerMaxSum(n, stickers) << '\n';
    }

}