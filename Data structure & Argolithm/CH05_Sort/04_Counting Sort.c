#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VALUE 1001

int n, m;
int a[MAX_VALUE];
//���� �ε����� ��� ���� ���� ������Ų��.
//==> ũ�⸦ �������� ����
//==> �޸�ȿ���� ���������� �ӵ��� ����.
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		a[m]++;
	}
	for (int i = 0; i < MAX_VALUE; i++) {
		while (a[i] != 0) {
			printf("%d ", i); //���ʴ�� ������ ������ŭ ���
			a[i]--;
		}
	}
	system("pause");
}