#include <iostream>
using namespace std;

int arr[5] = { 1,2,3,4,5 };
bool visited[5];
int com[5];

void print_com(void) {
	for (int i = 0; i < 2; i++) {
		cout << com[i] << ' ';
	}
	return;
}

void DFS(int idx, int depth) {
	if (2 == depth) {
		print_com();
		cout << '\n';
		return;
	}
	for (int i = idx; i < 5; i++) {
		if (visited[i]) 
			continue;
		visited[i] = true;
		com[depth] = arr[i];
		DFS(i + 1, depth + 1);
		visited[i] = false;
	}
}

int main(void) {
	//DFS·Î ¼ø¿­
	DFS(0, 0);
}
