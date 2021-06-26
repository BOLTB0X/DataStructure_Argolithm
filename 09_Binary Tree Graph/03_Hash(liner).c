#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000

typedef struct {
	int id;
	char name[20];
} Student;

//�ؽ� ���̺� �ʱ�ȭ
void init(Student** hashTable) {
	for (int i = 0; i < TABLE_SIZE; i ++) {
		hashTable[i] = NULL;
	}
}

//�ؽ� ���̺��� �޸𸮸� ��ȯ
void destructor(Student** hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i] != NULL) {
			free(hashTable[i]);
		}
	}
}

//�ؽ����̺� �� �� ������ ���� Ž������ ã�´�,
int findEmpty(Student** hashTable, int id) {
	int i = id % TABLE_SIZE;
	while (1){
		if (hashTable[i % TABLE_SIZE] == NULL) {
			return i % TABLE_SIZE;
		}
		i++;
	}
}

//Ư���� ID���� ��Ī�Ǵ� �����͸� �ؽ����̺� ������ ã�´�.
int search(Student** hashTable, int id) {
	int i = id % TABLE_SIZE;
	while (1){
		if (hashTable[i % TABLE_SIZE] == NULL) return -1;
		else if (hashTable[i % TABLE_SIZE]->id == id) return i;
		i++;
	}
}

//Ư���� Ű �ε����� �����͸� ����
void add(Student** hashTable, Student* input, int key) {
	hashTable[key] = input;
}

//�ؽ� ���̺����� Ư���� Ű�� �����͸� ��ȯ
Student* getValue(Student** hashTable, int key) {
	return hashTable[key];
}

//�ؽ� ���̺��� �����ϴ� ��� �����͸� ����մϴ�.
void show(Student** hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i] != NULL) {
			printf("Ű: [%d] �̸�: [%s]\n", i, hashTable[i]->name);
		}
	}
}

int main(void) {
	Student** hashTable;
	hashTable = (Student**)malloc(sizeof(Student) * TABLE_SIZE);
	init(hashTable);

	for (int i = 1; i <= INPUT_SIZE; i++) {
		Student* student = (Student*)malloc(sizeof(Student));
		student->id = rand() % 100;
		sprintf(student->name, "���%d", student->id);
		if (search(hashTable, student->id) == -1) { //�ߺ��Ǵ� ID�� ����X
			int index = findEmpty(hashTable, student->id);
			add(hashTable, student, index);
		}
	}
	show(hashTable);
	destructor(hashTable);
	system("pause");
	return 0;
}