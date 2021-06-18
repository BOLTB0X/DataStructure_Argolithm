#include <iostream>
#include <queue>
using namespace std;

queue<int> que;

int main(void) {
	que.push(5);
	que.push(4);
	que.push(3);
	que.pop();

	while (!que.empty()) {
		cout << que.front() << ' ';
		que.pop();
	}
}