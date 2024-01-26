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

void insert_Sort(int n) {
	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j] < arr[j - 1])
				swap(&arr[j], &arr[j - 1]);
			else
				break;
		}
	}

	return;
}

int main(void) {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	insert_Sort(n);

	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);

	return 0;
}
