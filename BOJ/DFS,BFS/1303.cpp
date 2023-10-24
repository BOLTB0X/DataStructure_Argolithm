// 1303 전쟁 - 전투
// https://www.acmicpc.net/problem/1303
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[101][101];
int visited[101][101];

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

typedef struct {
	int y, x;
} Sol;

// 너비우선탐색
int BFS(int n, int m, int y, int x) {
	int ret = 1;
	visited[y][x] = 1;
	queue<Sol> que;
	que.push({ y,x });

	while (!que.empty()) {
		Sol cur =que.front();
		que.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			// 범위초과
			if (ny < 0 || nx < 0 || ny >= m || nx >= n)
				continue;

			// 재방문 및 같은 병사가 아니면
			if (visited[ny][nx] == 1)
				continue;

			if (board[ny][nx] == board[y][x]) {
				ret++;
				visited[ny][nx] = 1;
				que.push({ ny, nx });
			}
		}
	}

	return ret;
}

pair<int, int> solution(int n, int m) {
	pair<int, int> answer = { 0,0 };

	// 초기화
	for (int i = 0; i < m; ++i)
		memset(visited[i], 0, n);

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			// 아군이면
			if (board[i][j] == 'W' && visited[i][j] == 0) {
				int ret = BFS(n, m, i, j);
				answer.first += ret * ret;
			}
			// 적군이면
			else if (board[i][j] == 'B' && visited[i][j] == 0) {
				int ret = BFS(n, m, i, j);
				answer.second += ret * ret;
			}
		}
			
	}
	return answer;
}

int main(void) {
	int n, m;
	string tmp;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> tmp;
		for (int j = 0; j < n; ++j)
			board[i][j] = tmp[j];
	}

	pair<int, int> ret = solution(n, m);
	cout << ret.first << ' ' << ret.second;

	return 0;
}