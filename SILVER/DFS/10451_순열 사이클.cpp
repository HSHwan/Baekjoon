#include <iostream>
#include <vector>

using namespace std;

vector<int> graph;
vector<bool> visited;

void dfs(int v) {
    if (visited[v]) return;
    visited[v] = true;
    dfs(graph[v]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int testcase;
    cin >> testcase;

    while (testcase--) {
        int num;
        cin >> num;

        vector<bool>(num + 1, false).swap(visited);
        vector<int>(num + 1).swap(graph);
        for (int i = 1; i <= num; i++) {
            cin >> graph[i];
        }

        int cycleNum = 0;
        for (int i = 1; i <= num; i++) {
            if (!visited[i]) {
                dfs(i);
                cycleNum++;
            }
        }

        cout << cycleNum << '\n';
    }

}