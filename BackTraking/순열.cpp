#include <iostream>
using namespace std;

int arr[5] = { 1,2,3,4,5 };
bool visited[5];
int per[5];

void print_arr(void) {
	for (int i = 0; i < 2; i++) {
		cout << per[i] << ' ';
	}
	return;
}
void DFS(int depth) {
	if (depth == 2) {
		print_arr();
		cout << '\n';
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		per[depth] = arr[i];
		DFS(depth + 1);
		visited[i] = false;
	}
}

int main(void) {
	DFS(0);
	return 0;
}