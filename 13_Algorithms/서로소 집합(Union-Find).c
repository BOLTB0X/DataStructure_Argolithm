#include <stdio.h>

//재귀로 집합 찾기
int get_Set(int set[], int x) {
	if (set[x] == x)
		return x;
	return set[x] = get_Set(set, set[x]);
}

//두 집합 합치기
void union_Set(int set[], int a, int b) {
	a = get_Set(set, a);
	b = get_Set(set, b);

	if (a < b)
		set[b] = a;
	else
		set[a] = b;
	return;
}

//동일한 집합 내에 있는지 확인
int find_data_in_Set(int set[], int a, int b) {
	a = get_Set(set, a);
	b = get_Set(set, b);
	if (a == b)
		return 1;
	return 0;
}

int main(void) {
	int set[7];

	for (int i = 0; i < 7; ++i)
		set[i] = i;

	printf("원소 1,2,3\n");
	printf("연결 : 원소 4,5,6\n");

	union_Set(set, 1, 2);
	union_Set(set, 2, 3);
	union_Set(set, 4, 5);
	union_Set(set, 5, 6);

	printf("1 -> 4 같은 집합? : %d\n", find_data_in_Set(set, 1, 4));
	printf("원소 6이 속한 집합? : %d\n", get_Set(set, 6));

	printf("===============================\n");
	
	printf("1과 4 연결\n");
	union_Set(set, 1, 4);

	printf("1 -> 4 같은 집합? : %d\n", find_data_in_Set(set, 1, 4));
	printf("원소 6이 속한 집합? : %d\n", get_Set(set, 6));

	return 0;
}