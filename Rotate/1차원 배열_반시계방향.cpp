#include <iostream>
#include <algorithm>

using namespace std;

int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

void print_arr(void) {
	for (int x = 0; x < 10; x++) {
		cout << arr[x] << ' ';
	}
	cout << '\n';
}

int main(void) {
	print_arr();
	//�ݽð�������� n��ŭ �̵�
	rotate(arr, arr + 1, arr + 10);
	print_arr();
	//2 3 4 5 6 7 8 9 10 1
	return 0;
}