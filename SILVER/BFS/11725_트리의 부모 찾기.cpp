#include <iostream>
#include <vector>
#include <queue>
#define ROOT 1
using namespace std;

int nodeNum;
vector<vector<int>> tree;
vector<int> rootNodes;

void bfs(int node) {
    queue<int> nodeQ;
    nodeQ.push(node);
    vector<bool> visited(nodeNum + 1);
    visited[node] = true;

    while (!nodeQ.empty()) {
        int nowNode = nodeQ.front();
        nodeQ.pop();

        for (int nextNode : tree[nowNode]) {
            if (!visited[nextNode]) {
                visited[nextNode] = true;
                nodeQ.push(nextNode);
                rootNodes[nextNode] = nowNode;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> nodeNum;

    tree.assign(nodeNum + 1, vector<int>());

    int nodeA, nodeB;
    for (int i = 0; i < nodeNum - 1; i++) {
        cin >> nodeA >> nodeB;
        tree[nodeA].push_back(nodeB);
        tree[nodeB].push_back(nodeA);
    }

    rootNodes.resize(nodeNum + 1);
    bfs(ROOT);

    for (int i = 2; i <= nodeNum; i++) {
        cout << rootNodes[i] << '\n';
    }
}