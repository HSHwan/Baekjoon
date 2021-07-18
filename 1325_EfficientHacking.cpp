// DFS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
const int N_MAX = 10001;

using namespace std;

vector<int> trust_computers[N_MAX];
bool visit[N_MAX];
vector<int> hacking_computers;
int hacking_num = 0;
int MAX_hacking = -1;

void output() {
	for (const auto computer : hacking_computers)
		cout << computer << " ";
}

void dfs(int start) {
	visit[start] = true;

	for (unsigned int i = 0; i < trust_computers[start].size(); i++) {
		int next_node = trust_computers[start][i];
		if (!visit[next_node]) {
			hacking_num++;
			dfs(next_node);
		}

	}
}

void dfsAll(int computer_max) {
	for (int i = 1; i <= computer_max; i++) {
		memset(visit, false, sizeof(visit));
		hacking_num = 0; // 해킹 가능한 컴퓨터 수
		dfs(i);

		if (MAX_hacking == hacking_num)
			hacking_computers.push_back(i);

		else if (MAX_hacking < hacking_num) {
			MAX_hacking = hacking_num;
			hacking_computers.clear();
			hacking_computers.push_back(i);
		}	
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M; // N : N 개의 컴퓨터, M : M 번의 신뢰 관계
	cin >> N >> M;

	int be, trusted; // be : 신뢰하는 입장, trusted : 신뢰받는 입장
	for (int i = 0; i < M; i++) {
		cin >> be >> trusted;
		trust_computers[trusted].push_back(be);
	}

	dfsAll(N);
	output();
}