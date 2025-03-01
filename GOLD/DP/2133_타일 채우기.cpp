#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;

    vector<int> tiles(num + 1, 0);

    tiles[2] = 3;
    for (int i = 4; i <= num; i += 2) {
        tiles[i] += tiles[2] * tiles[i - 2];
        for (int j = i - 4; j >= 2; j -= 2) {
            tiles[i] += 2 * tiles[j];
        }
        tiles[i] += 2;
    }

    cout << tiles[num];
}