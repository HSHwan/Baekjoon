#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartiteGraph(vector<vector<int>> graph, int vertex) {
    queue<int> vertexQ;
    vector<int> vertexColor(vertex + 1, 0);

    for (int i = 1; i <= vertex; i++) {
        if (vertexColor[i] != 0)    continue;

        vertexQ.push(i);
        vertexColor[i] = -1;

        while (!vertexQ.empty()) {
            int nowPos = vertexQ.front();
            vertexQ.pop();
            for (int nextV : graph[nowPos]) {
                if (vertexColor[nowPos] == vertexColor[nextV]) {
                    return false;
                }
                if (!vertexColor[nextV]) {
                    vertexColor[nextV] = -vertexColor[nowPos];
                    vertexQ.push(nextV);
                }
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    
    int vertex, edge;
    while (testcase--) {
        cin >> vertex >> edge;

        vector<vector<int>> graph(vertex + 1);
        int va, vb;
        for (int i = 0; i < edge; i++) {
            cin >> va >> vb;
            graph[va].push_back(vb);
            graph[vb].push_back(va);
        }

        if (isBipartiteGraph(graph, vertex))
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }
    
}