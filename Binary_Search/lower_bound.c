#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//이분탐색 응용
int lower_bound(int* arr, int size, int target) {
	int start, mid, end;
	start = 0, end = size - 1;

	// end가 start보다 같거나 작아지면, 
	// 그 값이 Upper Bound이므로 반복을 종료
	while (start < end) {
		mid = (start + end) / 2;
		
		//타겟이 중간값 보다 작거나 같다면
		if (arr[mid] >= target)
			end = mid;
		
		//타겟이 중간값보다 크다면
		else if (arr[mid] < target) 
			start = mid + 1; //중앙값 +1 
	}
	return end;
}

int main(void) {
	int arr[10] = { 1,3,4,5,7,9,10,11,12,15 };
	int arr_size = 10;
	
	//특정 값 이상이 되는 첫번째 인덱스를 구해야할 때 lower_bound 이용
	printf("3이상 되는 index: %d\n", lower_bound(arr, arr_size, 3));
	return 0;
}
