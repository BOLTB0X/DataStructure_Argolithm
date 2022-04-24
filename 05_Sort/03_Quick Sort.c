#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define Size 1000

int arr[Size];

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}

void Quick_Sort(int n, int start, int end) {
	if (start >= end)
		return;

	int pivot = start, left = start + 1, right = end;

	while (left <= right) {
		while (left <= end && arr[left] <= arr[pivot])
			left++;
		while (right > start && arr[right] >= arr[pivot])
			right--;

		if (left < right)
			swap(&arr[left], &arr[right]);
		else
			swap(&arr[pivot], &arr[right]);
	}

	Quick_Sort(n, start, right - 1);
	Quick_Sort(n, right + 1, end);
	return;
}

int main(void) {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	Quick_Sort(n, 0, n - 1);

	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	return 0;
}
