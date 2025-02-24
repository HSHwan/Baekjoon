#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> tiles(n + 1, 0);
    tiles[1] = 1;
    tiles[2] = 3;

    for (int i = 3; i <= n; i++) {
        tiles[i] = (tiles[i - 1] + tiles[i - 2]) % 10007;
    }

    cout << tiles[n];
}