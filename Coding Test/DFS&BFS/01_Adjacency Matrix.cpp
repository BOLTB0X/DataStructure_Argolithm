#include <iostream>
#define INF 99999999999 //무한의 비용선언

using namespace std;

int graph[3][3] = {
	{0,7,5},
	{7,0,INF},
	{5,INF,0}
};

int main(void) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
}