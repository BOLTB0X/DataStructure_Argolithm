#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100000

int a[MAX_SIZE];
int founded=0;

int search(int start, int end, int target) {
	if (start > end) return -9999;
	int mid = (start + end) / 2;
	if (a[mid] == target) return mid;
	//재귀적 호출
	else if (a[mid] > target) return search(start, mid - 1, target);
	else return search(mid + 1, end, target);
}
int main(void) {
	int n, target;
	printf("배열의 길이:");
	scanf("%d", &n);
	printf("찾을 값:");
	scanf("%d",&target);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int result = search(0, n - 1, target);
	if (result != -9999) printf("%d번째 원소\n", result + 1);
	else printf("원소를 찾을 수 없음\n");
	system("pause");
	return 0;
}