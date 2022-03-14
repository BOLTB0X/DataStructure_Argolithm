#include <iostream>

using namespace std;

int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
int c_arr[3][3];

//시계방향 90도씩 회전
void f_rotate(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//여기를 바꿔줌
			c_arr[i][j] = arr[n - 1 - j][i];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = c_arr[i][j];
		}
	}
	return;
}

void print_arr(void) {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cout << arr[y][x] << ' ';
		}
		cout << '\n';
	}
}

int main(void) {
	print_arr();
	cout << '\n';
	f_rotate(3);
	print_arr();
	cout << '\n';
	return 0;
}
