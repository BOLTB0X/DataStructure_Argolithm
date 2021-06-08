#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000

int a[SIZE];

int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int start, int end) {
	if (start >= end) return;
	int key = start, i = start + 1, j = end, temp; //i는 왼쪽 j는 오른쪽, 피벗 값을 가장 왼쪽으로 가정
	while (i<=j) { //엇갈리기 전까지 반복
		while (i <= end && a[i] <= a[key]) i++; //key보다 큰 값이 i에 담긴다.
		while (j > start && a[j] >= a[key]) j--; //key보다 작은 값이 j에 담기도록
		if (i > j) swap(&a[key], &a[j]);
		else swap(&a[i], &a[j]);
	}
	 // 엇갈릴 때 부분적 재귀적으로 호출
	quickSort(start, j - 1);
	quickSort(j + 1, end);
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	quickSort(0, n - 1);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	system("pause");
	return 0;
}