#include <iostream>
#include <vector>
#define MOD 1'000'000

using namespace std;

int solveCryptoCaseNum(string crypto) {
    if (crypto[0] == '0')
        return 0;
    
    int cryptoLen = crypto.size();
    vector<int> cryptoCase(cryptoLen + 1, 0);
    cryptoCase[0] = 1;
    cryptoCase[1] = 1;
    
    for (int i = 1; i < cryptoLen; i++) {
        if (crypto[i] != '0')
            cryptoCase[i + 1] = (cryptoCase[i + 1] + cryptoCase[i]) % MOD;
        if (crypto[i - 1] == '1' || (crypto[i - 1] == '2' && crypto[i] <= '6'))
            cryptoCase[i + 1] = (cryptoCase[i + 1] + cryptoCase[i - 1]) % MOD;
    }

    return cryptoCase[cryptoLen];
}

int main() {
    string crypto;
    cin >> crypto;

    int cryptoCaseNum = solveCryptoCaseNum(crypto);
    cout << cryptoCaseNum;
}