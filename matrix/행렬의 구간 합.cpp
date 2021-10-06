#include <stdio.h>

int N = 6;
int S[7][7];

void printState(int arr[7][7], int size_t) {
    for (int i = 1; i <= size_t; ++i) {
        for (int j = 1; j <= size_t; ++j) {
            printf("%2d ", arr[i][j]);
        }
        puts("");
    }
    puts("");
}
int main() {
    int map[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
    };
    // (1, 1) ~ (x, y) 까지의 합
    // S[x][y] = S[x - 1][y] + S[x][y - 1] - S[x - 1][y - 1] + map[x][y]
    for (int y = 1; y <= 7; ++y) {
        for (int x = 1; x <= 7; ++x) {
            S[x][y] = S[x - 1][y] + S[x][y - 1] - S[x - 1][y - 1] + map[x][y];
        }
    }
    printState(S, N);
}