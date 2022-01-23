#include <iostream>

using namespace std;

int arr[1000][1000] = { 0, }; 

void rotate(int n) {
    int cnt = 1; 

    int column_l = 0;  //열 왼쪽
    int column_r = n - 1; //행 오른쪽
    int row_u = 0;  // 행 위
    int row_d = n - 1;  // 행 아래
    int x = 0, y = 0; 

    while (cnt <= n * n) {
        for (x = column_l; x <= column_r && cnt <= n * n; x++) 
            arr[y][x] = cnt++;
        x--;
        row_u++;

        for (y = row_u; y <= row_d && cnt <= n * n; y++) 
            arr[y][x] = cnt++;
        y--;
        column_r--;

        for (x = column_r; x >= column_l && cnt <= n * n; x--) 
            arr[y][x] = cnt++;
        x++;
        row_d--;

        for (y = row_d; y >= row_u && cnt <= n * n; y--) 
            arr[y][x] = cnt++;
        y++;
        column_l++;
    }

    return;
}

void solution(void) {
    int n;

    cin >> n;

    rotate(n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}
