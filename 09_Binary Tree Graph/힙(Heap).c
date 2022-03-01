#include <stdio.h>
#include <stdlib.h>
#define MS 100000

typedef struct {
	int data[MS];
	int heap_size;
} heap; //�� ����

heap* init(heap* h) {
	h = (heap*)malloc(sizeof(heap));
	h->heap_size = 0;
	return h;
}

void add(heap* h, int data) {
	//�� �������� ����
	h->heap_size++;
	h->data[h->heap_size] = data;

	int me = h->heap_size;
	int parent = me / 2;

	// ��Ʈ���� �ö� �� �����Ƿ� �θ��� �ε�����ȣ�� 1�̻�
	while (parent) {
		// �θ� ������ ���� �����Ƿ� ���� �θ���ġ�� �����Ѵ�.
		if (h->data[parent] < h->data[me]) {
			int tmp = h->data[parent];
			h->data[parent] = h->data[me];
			h->data[me] = tmp;

			me = parent;
			parent = me / 2;
		}
		else
			break;
	}

	return;
}


int empty(heap* h) {
	//������
	return (h->heap_size ? 0 : 1);
}

int remove(heap* h) {
	// ���� ū���� res �� ����
	int res = h->data[1];
	// �� ������ �����͸� ������ �ø�����
	h->data[1] = h->data[h->heap_size];
	// ũ�⸦ 1 ���ҽ�Ŵ
	h->heap_size -= 1;

	int me = 1;
	int child = 2;
	// �ڽ��� �ε����� �� ũ�⺸�� �۰ų� ������ �ݺ�
	while (child <= h->heap_size) {
		// ������ �ڽ��� �ε�����ȣ�� �� ũ�� �����̸鼭 ���� �ڽĺ��� �� ū���
		if (child + 1 <= h->heap_size && h->data[child] < h->data[child + 1]) {
			// ���� �ڽ��� �ε����� ���������� �ٲ���
			child += 1;
		}

		// ������ �� �ڽ��� ��ũ�ٸ� ���� �ٲ��ְ� 
		if (h->data[me] < h->data[child]) {
			int temp = h->data[me];
			h->data[me] = h->data[child];
			h->data[child] = temp;

			// �� ��ġ�� �ٲ� �ε�����ġ�� 
			me = child;
			child = me * 2;
		}
		// ���� �� ũ�ٸ� �ڸ��� ã�����Ƿ� ����.
		else 
			break;
	}
	return res;
}

int main() {
	heap* h = NULL;
	h = init(h);

	add(h, 3);
	add(h, 5);
	add(h, 1);
	add(h, 23);
	add(h, 9);

	while (!empty(h)) {
		printf("%d ", remove(h));
	}

	return 0;
}