#include <iostream>
using namespace std;

int binary_search(int* arr, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		//타겟이 딱 중간점인 경우
		if (arr[mid] == target) {
			return mid;
		}
		//타켓이 중간점보다 작은 경우
		//즉 왼쪽으로
		else if (arr[mid] > target)
			end = mid - 1;
		//타켓이 중간점보다 큰 경우
		//즉 오른쪽으로
		else
			start = mid + 1;
	}
	//못찾는 경우
	return -1;
}