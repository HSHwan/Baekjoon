#include <iostream>
#include <vector>

using namespace std;

vector<int> graph;
vector<bool> visited, done;
int teammateCount;

void dfs(int v) {
    visited[v] = true;
    int nextV = graph[v];
    if (!visited[nextV])
        dfs(nextV);
    else if (!done[nextV]) {
        for (int i = nextV; i != v; i = graph[i]) {
            teammateCount++;
        }
        teammateCount++;
    }
    done[v] = true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int testcase;
    cin >> testcase;

    while (testcase--) {
        int studentNum;
        cin >> studentNum;

        graph.resize(studentNum + 1);
        visited.assign(studentNum + 1, false);
        done.assign(studentNum + 1, false);

        for (int i = 1; i <= studentNum; i++) {
            cin >> graph[i];
        }

        teammateCount = 0;
        
        for (int i = 1; i <= studentNum; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        cout << studentNum - teammateCount << '\n';
    }
}