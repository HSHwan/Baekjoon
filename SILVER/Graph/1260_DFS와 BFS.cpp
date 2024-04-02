#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FOR(i, N) for (int i = 0; i < N; i++)
using namespace std;

int vertexNum, edgeNum, targetVertex;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> DFSResult, BFSResult;

void input(){
    cin >> vertexNum >> edgeNum >> targetVertex;
    vector<vector<int>>(vertexNum + 1).swap(graph);

    int vertexA, vertexB;
    FOR(i, edgeNum){
        cin >> vertexA >> vertexB;
        graph[vertexA].push_back(vertexB);
        graph[vertexB].push_back(vertexA);
    }
}

void init(){
    vector<bool>(vertexNum + 1, false).swap(visited);
}

void DFS(const int& target){
    visited[target] = true;
    DFSResult.push_back(target);
    for (const int& connectedVertex : graph[target]){
        if (!visited[connectedVertex])
            DFS(connectedVertex);
    }
}

void BFS(const int& target){
    int nowVertex = target;
    queue<int> nextVertex;
    nextVertex.push(nowVertex);
    visited[nowVertex] = true;

    while (!nextVertex.empty()){
        nowVertex = nextVertex.front();
        nextVertex.pop();
        BFSResult.push_back(nowVertex);

        for (const int& connectedVertex : graph[nowVertex]){
            if (!visited[connectedVertex]){
                nextVertex.push(connectedVertex);
                visited[connectedVertex] = true;
                
            }
        }
    }
}

void solve(){
    for (int i = 1; i <= vertexNum; i++){
        if (!graph[i].empty())
            sort(graph[i].begin(), graph[i].end());
    }
    
    init();
    DFS(targetVertex);
    init();
    BFS(targetVertex);
}

void output(){
    for (const int& vertex : DFSResult)
        cout << vertex << ' ';
    cout << '\n';
    for (const int& vertex : BFSResult)
        cout << vertex << ' ';
}

int main(){
    input ();
    solve ();
    output();
}