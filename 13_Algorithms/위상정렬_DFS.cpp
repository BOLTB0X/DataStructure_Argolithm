#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool visited[32001];
stack<int> topo;

void DFS(vector<vector<int>> &adj, int startNode) {
	visited[startNode] = true;
	for (int i = 0; i < adj[startNode].size(); i++)
		if (!visited[adj[startNode][i]]) DFS(adj, adj[startNode][i]);
	topo.push(startNode);
}
int main() {
	int N, M, A, B;
	cin >> N >> M;
	vector<vector<int>> adj(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		adj[A].push_back(B);
	}
	for (int i = 1; i <= N; i++) 
		if (!visited[i]) 
			DFS(adj, i);
	while (!topo.empty()) {
		cout << topo.top() << ' ',
			topo.pop();
	}
	return 0;
}