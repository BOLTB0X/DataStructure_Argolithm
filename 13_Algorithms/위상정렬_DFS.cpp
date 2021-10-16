#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool visited[32001];
stack<int> topo;

//깊이 우선 탐색을 이용하여 위상정렬
void DFS(vector<vector<int>> &adj, int startNode) {
	visited[startNode] = true;

	//기존 인접그래프 방식으로
	//계속 진행
	for (int i = 0; i < adj[startNode].size(); i++) {
		int next = adj[startNode][i];
		if (!visited[next])
			DFS(adj, next);
	}
	//현재 스타트노드 삽입
	topo.push(startNode);
}

int main() {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, A, B;
	cin >> N >> M;
	
	//인접그래프 생성
	vector<vector<int>> adj(N + 1);

	//인접그래프 생성
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		adj[A].push_back(B);
	}

	//위상정렬
	//각 미방문 노드를 탐색하여 스택에 줄 세울 원소들을 스택
	for (int i = 1; i <= N; i++) 
		if (!visited[i]) 
			DFS(adj, i);
	
	//상단에 즉 스택의 특성상 마지막에 들어온 것들이 먼저 
	while (!topo.empty()) {
		cout << topo.top() << ' ';
		topo.pop();
	}
	return 0;
}
