#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000

//계수정렬만큼 빠른 알고리즘
//자릿수를 기준으로 
//ex 1의 자리로 자릿수 누적 배열을 구하고 
// 누적값을 결과 배열 위치에 뒤에서 부터 처리

void radixSort(int* a, int n) {
	int res[MAX], maxValue = 0;
	int exp = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] > maxValue) maxValue = a[i];
	}
	while (maxValue/exp > 0){ //1의 자리부터 계산
		int bucket[10] = { 0 };
		for (int i = 0; i < n; i++) bucket[a[i] / exp % 10]++;
		//자릿수 배열 처리
		for (int i = 1; i < 10; i++) bucket[i] += bucket[i - 1];
		//누적 계산 
		for (int i = n - 1; i >= 0; i--) { //같은 자릿수 끼리는 순서를 유지
			res[--bucket[a[i] / exp % 10]] = a[i];
		}
		for (int i = 0; i < n; i++) a[i] = res[i]; //기본 배열 갱신
		exp *= 10;
	}
}

int main(void) {
	int a[MAX];
	int i, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	radixSort(a, n);
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
}