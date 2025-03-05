#include <iostream>
#include <vector>
#define ROOT -1

using namespace std;

vector<int> rootVertex;

int findRoot(int v) {
    if (rootVertex[v] == ROOT)  return v;
    return rootVertex[v] = findRoot(rootVertex[v]);
}

void unionVertex(int a, int b) {
    int root1 = findRoot(a);
    int root2 = findRoot(b);
    if (root1 != root2) {
        rootVertex[root2] = root1;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    int vertex, edge;
    cin >> vertex >> edge;

    vector<int>(vertex + 1, ROOT).swap(rootVertex);

    int va, vb;
    for (int i = 0; i < edge; i++) {
        cin >> va >> vb;
        unionVertex(va, vb);
    }

    int componentNum = 0;
    for (int i = 1; i <= vertex; i++) {
        if (rootVertex[i] == ROOT)
            componentNum++;
    }

    cout << componentNum;
}