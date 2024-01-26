#include <iostream>

using namespace std;

int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
int c_arr[3][3];

//xÃà ´ëÄª
void rotate(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c_arr[i][j] = arr[n - i - 1][j];
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
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			cout << arr[x][y] << ' ';
		}
		cout << '\n';
	}
}

int main(void) {
	print_arr();
	cout << '\n';
	rotate(3);
	print_arr();
	cout << '\n';
	return 0;
}