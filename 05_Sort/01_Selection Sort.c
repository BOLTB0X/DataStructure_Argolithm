#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<limits.h>
#define SIZE 1000

int arr[SIZE];
int swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int n, min, index;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		min = INT_MAX; //제일 큰값으로 초기화
		for (int j = i; j < n; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		swap(&arr[i], &arr[index]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}