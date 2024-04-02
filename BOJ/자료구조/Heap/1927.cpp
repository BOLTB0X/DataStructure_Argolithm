// 1927 최소 힙
// https://www.acmicpc.net/problem/1927
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//구조체
struct compare {
	bool operator() (int x, int y) {
		return x > y;
	}
};

void solution(void) {
	int n;
	//최소힙
	priority_queue<int,vector<int>,compare> pq;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int value;
		cin >> value;

		if (value == 0) {
			if (pq.empty())
				printf("0\n");
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(value);
		}
	}

	return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}