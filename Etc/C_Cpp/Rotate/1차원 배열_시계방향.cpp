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
	//시계방향으로 n만큼 이동
	// (arr.size() - n)  (arr.size())
	rotate(arr, arr + 9, arr + 10);
	print_arr();
	//2 3 4 5 6 7 8 9 10 1
	return 0;
}