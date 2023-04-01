#include <iostream>

using namespace std;

int main(void) {
	int graph[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 2, 3, 4, 5, 6},
        {0, 2, 2, 2, 2, 2, 2},
        {0, 3, 3, 3, 3, 3, 3},
        {0, 4, 4, 4, 4, 4, 4},
        {0, 5, 5, 5, 5 ,5 ,5},
        {0, 6, 6, 6, 6, 6, 6},
	};

    int start_y, start_x, end_y, end_x;
    start_y = 2, start_x = 4;
    end_y = 5, end_x = 5;

    for (int i = start_y; i <= end_y; ++i) {
        for (int j = start_x; j <= end_x; ++j) {
            printf("%2d ", graph[i][j]);
        }
        cout << '\n';
    }
}