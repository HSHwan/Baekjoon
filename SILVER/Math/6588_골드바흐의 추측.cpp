#include <iostream>
#include <vector>
#define MAX 1000000

using namespace std;

void setPrimeNumber(vector<bool>& isPrime, int num) {
    for (int i = 2; i * i <= num; i++) {
        if (!isPrime[i]) continue;
        for (int j = 2 * i; j < num; j += i) {
            isPrime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL); cout.tie(NULL);

    int num = -1;

    vector<bool> isPrime(MAX, true);
    setPrimeNumber(isPrime, MAX);

    while (num) {
        cin >> num;

        int end = num / 2;
        for (int i = 3; i <= end; i += 2) {
            if (isPrime[i] && isPrime[num - i]) {
                cout << num << " = " << i << " + " << num - i << '\n';
                break;
            }
            if (end < (i + 2)) {
                cout << "Goldbach's conjecture is wrong.\n";
            }
        }
    }

}