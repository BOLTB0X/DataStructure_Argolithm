#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10000

//�ִ� ���� �θ��尡 �ڽĳ�庸�� ���� ū ���� ���� Ʈ��
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

typedef struct {
	int heap[MAX_SIZE];
	int cnt;
} priorityQueue;

//���� ����Ʈ���� �����ϴ� ���·� ���������� ����
void push(priorityQueue* pq, int data) {
	if (pq->cnt >= MAX_SIZE) return;
	pq->heap[pq->cnt] = data;
	int now = pq->cnt;
	int parent = (pq->cnt - 1) / 2;
	//�� ���Ҹ� ������ ���Ŀ� ��������� ���� �����Ѵ�.
	while (now>0 && pq->heap[now] >pq->heap[parent]){
		swap(&pq->heap[now], &pq->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->cnt++;
}

//pop�� ���� ��Ʈ��带 �����ϰ� ���� ������ ���Ҹ� ��Ʈ ����� ��ġ�� �Ű���
int pop(priorityQueue* pq) {
	if (pq->cnt <= 0) return -9999;
	int res = pq->heap[0];
	pq->cnt--;
	pq->heap[0] = pq->heap[pq->cnt];
	int now = 0, leftChild=1,rightChild=2;
	int target = now;
	//�� ���Ҹ� ������ ���Ŀ� ��������� ���� �����Ѵ�.
	while (leftChild<pq->cnt){
		if (pq->heap[target] < pq->heap[leftChild]) target = leftChild;
		if (pq->heap[target] < pq->heap[rightChild] && rightChild < pq->cnt) target = rightChild;
		if (target == now) break; // �� �̻� �������� �ʾƵ� �� �� ����
		else {
			swap(&pq->heap[now], &pq->heap[target]);
			now = target;
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 2;
		}
	}
	return res;
}

int main(void) {
	int n, data;
	scanf("%d", &n);
	priorityQueue pq;
	pq.cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		push(&pq, data);
	}
	for (int i = 0; i < n; i++) {
		int data = pop(&pq);
		printf("%d ", data);
	}
	printf("\n");
	system("pause");
	return 0;
}