#include <iostream>
#include <vector>
#define NODE first
#define DIST second
#define ROOT 1

using namespace std;

typedef pair<int, int> pii;

int nodeNum;
vector<vector<pii>> tree;
vector<bool> visited;
int targetNode, targetNodeDist;

void dfs(int node, int dist) {
    visited[node] = true;

    if (dist > targetNodeDist) {
        targetNode = node;
        targetNodeDist = dist;
    }

    for (pii edge : tree[node]) {
        if (!visited[edge.NODE]) {
            dfs(edge.NODE, dist + edge.DIST);   
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> nodeNum;
    tree.assign(nodeNum + 1, vector<pii>());

    int parentNode, childNode, edgeLen;
    for (int i = 0; i < nodeNum - 1; i++) {
        cin >> parentNode >> childNode >> edgeLen;
        tree[parentNode].push_back({childNode, edgeLen});
        tree[childNode].push_back({parentNode, edgeLen});
    }

    visited.assign(nodeNum + 1, false);
    dfs(ROOT, 0);

    int startNode = targetNode;
    targetNode = 0;
    targetNodeDist = 0;

    vector<bool>(nodeNum + 1, false).swap(visited);
    dfs(startNode, 0);

    cout << targetNodeDist;
}