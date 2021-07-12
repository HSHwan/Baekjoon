// DP - Knapsack Problem
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int m[101];
int c[101];
int DP[101][10001];

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> m[i];
    }

    int cost_min, cost_max_sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
        if (i == 1)
            cost_min = c[i];
        if (cost_min > c[i])
            cost_min = c[i];
        cost_max_sum += c[i];
    }

    int cost_min_sum = cost_max_sum;
    for (int i = 1; i <= N; i++) {
        for (int j = cost_min; j <= cost_max_sum; j++) {
            if (j >= c[i])
                DP[i][j] = max(m[i] + DP[i - 1][j - c[i]], DP[i - 1][j]);
            else
                DP[i][j] = DP[i - 1][j];

            if (DP[i][j] >= M) {
                cost_min_sum = min(cost_min_sum, j);
                break;
            } 
        }
    }

    cout << cost_min_sum;
    return 0;
}