#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node* leftChild;
	struct Node* rightChild;
} Node;

Node* initNode(int data, Node* leftChild, Node* rightChild) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftChild = leftChild;
	node->rightChild = rightChild;
	return node;
} //초기화 노드

//전위 순회
void preorder(Node* root) {
	if (root) {
		printf("%d ", root->data); //자기 자신을 출력,즉 root부터 출력
		preorder(root->leftChild); //왼쪽 자식을 방문
		preorder(root->rightChild); //오른쪽 자식을 방문
	}
}

//중위 순회
void inorder(Node* root) {
	if (root) {
		inorder(root->leftChild); //왼쪽 자식을 방문
		printf("%d ", root->data); //왼쪽-->오른쪽 출력
		inorder(root->rightChild); //오른쪽 자식 방문
	}
}
//후위 순회
void postorder(Node* root) {
	if (root) {
		postorder(root->leftChild); //왼쪽 자식 방문
		postorder(root->rightChild); //오른쪽 자식 방문
		printf("%d ", root->data); //root가 가장 마지막으로 방문
	}
}

int main(void) {
	Node* n7 = initNode(50, NULL, NULL);
	Node* n6 = initNode(37, NULL, NULL);
	Node* n5 = initNode(23, NULL, NULL);
	Node* n4 = initNode(5, NULL, NULL);


	Node* n3 = initNode(48, n6, n7);
	Node* n2 = initNode(17, n4, n5);
	Node* n1 = initNode(30, n2, n3);
	preorder(n1); //전위 순회 출력: 30 17 5 23 48 37 50
	printf("\n");
	inorder(n1); //중위 순회 출력: 5 17 23 30 37 48 50
	printf("\n");
	postorder(n1); //후위 순회 출력: 5 23 17 30 37 50 48 30
	system("pause");
	return 0;
}