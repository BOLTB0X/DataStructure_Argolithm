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

void select_Sort(int n) {
	int min_idx;
	for (int i = 0; i < n - 1; ++i) {
		min_idx = i;
		for (int j = i; j < n; ++j) {
			if (arr[min_idx] > arr[j]) 
				min_idx = j;
		}
		swap(&arr[i], &arr[min_idx]);
	}

	return;
}

int main(void) {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	select_Sort(n);

	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);

	return 0;
}
