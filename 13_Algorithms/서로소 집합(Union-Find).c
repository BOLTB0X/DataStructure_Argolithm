#include <stdio.h>

//��ͷ� ���� ã��
int get_Set(int set[], int x) {
	if (set[x] == x)
		return x;
	return set[x] = get_Set(set, set[x]);
}

//�� ���� ��ġ��
void union_Set(int set[], int a, int b) {
	a = get_Set(set, a);
	b = get_Set(set, b);

	if (a < b)
		set[b] = a;
	else
		set[a] = b;
	return;
}

//������ ���� ���� �ִ��� Ȯ��
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

	printf("���� 1,2,3\n");
	printf("���� : ���� 4,5,6\n");

	union_Set(set, 1, 2);
	union_Set(set, 2, 3);
	union_Set(set, 4, 5);
	union_Set(set, 5, 6);

	printf("1 -> 4 ���� ����? : %d\n", find_data_in_Set(set, 1, 4));
	printf("���� 6�� ���� ����? : %d\n", get_Set(set, 6));

	printf("===============================\n");
	
	printf("1�� 4 ����\n");
	union_Set(set, 1, 4);

	printf("1 -> 4 ���� ����? : %d\n", find_data_in_Set(set, 1, 4));
	printf("���� 6�� ���� ����? : %d\n", get_Set(set, 6));

	return 0;
}