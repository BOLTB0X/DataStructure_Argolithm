#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10000

//최대 힙은 부모노드가 자식노드보다 값이 큰 완전 이진 트리
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

typedef struct {
	int heap[MAX_SIZE];
	int cnt;
} priorityQueue;

//완전 이진트리를 유지하는 형태로 순차적으로 삽입
void push(priorityQueue* pq, int data) {
	if (pq->cnt >= MAX_SIZE) return;
	pq->heap[pq->cnt] = data;
	int now = pq->cnt;
	int parent = (pq->cnt - 1) / 2;
	//새 원소를 삽입한 이후에 상향식으로 힙을 구성한다.
	while (now>0 && pq->heap[now] >pq->heap[parent]){
		swap(&pq->heap[now], &pq->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->cnt++;
}

//pop할 때는 루트노드를 삭제하고 가장 마지막 원소를 루트 노드의 위치로 옮겨줌
int pop(priorityQueue* pq) {
	if (pq->cnt <= 0) return -9999;
	int res = pq->heap[0];
	pq->cnt--;
	pq->heap[0] = pq->heap[pq->cnt];
	int now = 0, leftChild=1,rightChild=2;
	int target = now;
	//새 원소를 추출한 이후에 하향식으로 힙을 구성한다.
	while (leftChild<pq->cnt){
		if (pq->heap[target] < pq->heap[leftChild]) target = leftChild;
		if (pq->heap[target] < pq->heap[rightChild] && rightChild < pq->cnt) target = rightChild;
		if (target == now) break; // 더 이상 내려가지 않아도 될 때 종료
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