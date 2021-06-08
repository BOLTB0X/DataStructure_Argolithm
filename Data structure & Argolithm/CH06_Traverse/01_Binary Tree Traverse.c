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
} //�ʱ�ȭ ���

//���� ��ȸ
void preorder(Node* root) {
	if (root) {
		printf("%d ", root->data); //�ڱ� �ڽ��� ���,�� root���� ���
		preorder(root->leftChild); //���� �ڽ��� �湮
		preorder(root->rightChild); //������ �ڽ��� �湮
	}
}

//���� ��ȸ
void inorder(Node* root) {
	if (root) {
		inorder(root->leftChild); //���� �ڽ��� �湮
		printf("%d ", root->data); //����-->������ ���
		inorder(root->rightChild); //������ �ڽ� �湮
	}
}
//���� ��ȸ
void postorder(Node* root) {
	if (root) {
		postorder(root->leftChild); //���� �ڽ� �湮
		postorder(root->rightChild); //������ �ڽ� �湮
		printf("%d ", root->data); //root�� ���� ���������� �湮
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
	preorder(n1); //���� ��ȸ ���: 30 17 5 23 48 37 50
	printf("\n");
	inorder(n1); //���� ��ȸ ���: 5 17 23 30 37 48 50
	printf("\n");
	postorder(n1); //���� ��ȸ ���: 5 23 17 30 37 50 48 30
	system("pause");
	return 0;
}