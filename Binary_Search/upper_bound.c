#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int upper_bound(int* arr, int size, int target) {
	int start, mid, end;
	start = 0, end = size - 1;
	
	// end�� start���� ���ų� �۾�����, 
	// �� ���� Upper Bound�̹Ƿ� �ݺ��� ����
	while (start < end) {
		mid = (start + end) / 2;
		//Ÿ���� �߰��� ���� �۴ٸ�
		if (arr[mid] > target)
			end = mid;
		//Ÿ���� �߰������� ũ�ų� ���ٸ�
		else if (arr[mid] <= target) {
			start = mid + 1;
		}
	}
	return end;
}

int main(void) {
	int arr[10] = { 1,3,4,5,7,9,10,11,12,15 };
	int arr_size = 10;
	
	printf("3�ʰ� �Ǵ� index: %d\n", upper_bound(arr,arr_size,3));
	return 0;
}