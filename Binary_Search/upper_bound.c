#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int upper_bound(int* arr, int size, int target) {
	int start, mid, end;
	start = 0, end = size - 1;
	
	// end가 start보다 같거나 작아지면, 
	// 그 값이 Upper Bound이므로 반복을 종료
	while (start < end) {
		mid = (start + end) / 2;
		//타겟이 중간값 보다 작다면
		if (arr[mid] > target)
			end = mid;
		//타겟이 중간값보다 크거나 같다면
		else if (arr[mid] <= target) {
			start = mid + 1;
		}
	}
	return end;
}

int main(void) {
	int arr[10] = { 1,3,4,5,7,9,10,11,12,15 };
	int arr_size = 10;
	
	printf("3초과 되는 index: %d\n", upper_bound(arr,arr_size,3));
	return 0;
}