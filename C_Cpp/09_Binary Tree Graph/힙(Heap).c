#include <stdio.h>
#include <stdlib.h>
#define MS 100000

typedef struct {
	int data[MS];
	int heap_size;
} heap; //힙 정의

heap* init(heap* h) {
	h = (heap*)malloc(sizeof(heap));
	h->heap_size = 0;
	return h;
}

void add(heap* h, int data) {
	//맨 마지막에 삽입
	h->heap_size++;
	h->data[h->heap_size] = data;

	int me = h->heap_size;
	int parent = me / 2;

	// 루트까지 올라갈 수 있으므로 부모의 인덱스번호가 1이상
	while (parent) {
		// 부모가 나보다 값이 작으므로 내가 부모위치로 가야한다.
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
	//사이즈
	return (h->heap_size ? 0 : 1);
}

int remove(heap* h) {
	// 가장 큰값을 res 에 저장
	int res = h->data[1];
	// 맨 마지막 데이터를 맨위로 올린다음
	h->data[1] = h->data[h->heap_size];
	// 크기를 1 감소시킴
	h->heap_size -= 1;

	int me = 1;
	int child = 2;
	// 자식의 인덱스가 힙 크기보다 작거나 같으면 반복
	while (child <= h->heap_size) {
		// 오른쪽 자식의 인덱스번호가 힙 크기 이하이면서 왼쪽 자식보다 더 큰경우
		if (child + 1 <= h->heap_size && h->data[child] < h->data[child + 1]) {
			// 비교할 자식의 인덱스를 오른쪽으로 바꿔줌
			child += 1;
		}

		// 나보다 내 자식이 더크다면 값을 바꿔주고 
		if (h->data[me] < h->data[child]) {
			int temp = h->data[me];
			h->data[me] = h->data[child];
			h->data[child] = temp;

			// 내 위치를 바꾼 인덱스위치로 
			me = child;
			child = me * 2;
		}
		// 내가 더 크다면 자리를 찾았으므로 종료.
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