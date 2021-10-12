#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int lower_bound(int* arr, int size, int target) {
	int start, mid, end;
	start = 0, end = size - 1;

	// end�� start���� ���ų� �۾�����, 
	// �� ���� Upper Bound�̹Ƿ� �ݺ��� ����
	while (start < end) {
		mid = (start + end) / 2;
		//Ÿ���� �߰��� ���� �۰ų� ���ٸ�
		if (arr[mid] >= target)
			end = mid;
		//Ÿ���� �߰������� ũ�ٸ�
		else if (arr[mid] < target) {
			start = mid + 1;
		}
	}
	return end;
}

int main(void) {
	int arr[10] = { 1,3,4,5,7,9,10,11,12,15 };
	int arr_size = 10;

	printf("3�̻� �Ǵ� index: %d\n", lower_bound(arr, arr_size, 3));
	return 0;
}