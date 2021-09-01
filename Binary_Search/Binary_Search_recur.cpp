#include <iostream>
using namespace std;

int binary_search(int* arr, int target, int start, int end) {
	//못 찾는 경우
	if (start > end)
		return -1;
	int mid = (start + mid) / 2;
	//타겟이 중간점일 경우 인덱스 반환
	if (arr[mid] == target)
		return mid;
	//타겟이 중간점보다 작은 경우 ==> 왼쪽으로
	else if (arr[mid] > target)
		return binary_search(arr, target, start, mid - 1);
	//타겟이 큰 경우 ==> 오른쪽으로
	else
		return binary_search(arr, target, mid + 1, end);
}