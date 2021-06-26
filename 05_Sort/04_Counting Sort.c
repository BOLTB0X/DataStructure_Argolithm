#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VALUE 1001

int n, m;
int a[MAX_VALUE];
//값을 인덱스로 삼고 원소 값을 증가시킨다.
//==> 크기를 기준으로 정렬
//==> 메모리효율은 떨어지지만 속도는 높다.
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		a[m]++;
	}
	for (int i = 0; i < MAX_VALUE; i++) {
		while (a[i] != 0) {
			printf("%d ", i); //차례대로 원소의 개수만큼 출력
			a[i]--;
		}
	}
	system("pause");
}