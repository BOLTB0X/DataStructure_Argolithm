#include <stdio.h>
#include <stdlib.h>
#include "LL.h"


/**** 생성함수(모든걸 초기화) => Create ****/
void Create(List* plist)
{
	Node* head = NULL;      // NULL 포인터 초기화, 리스트 머리를 가르키는 포인터변수
	Node* tail = NULL;      // NULL 포인터 초기화, 리스트 꼬리를 가르키는 포인터변수
	Node* cur = NULL;       // NULL 포인터 초기화, 저장된 데이터의 조회하는 포인터변수
	plist->numOfData = 0;   // 데이터 수
}
/***추가함수(데이터 추가)*****/
void Add(List* plist, int pdata)
{
	Node* newNode = NULL; // NULL 포인터 초기화, 추가되는 노트의 포인터변수
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = pdata;
	newNode->next = NULL;
	if (plist->head == NULL && plist->tail == NULL) //머리 꼬리가 비어있을 경우
		plist->head = plist->tail = newNode;
	else
	{
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	(plist->numOfData)++;
}
/**** 삽입함수 => Insert ****/
void Insert(List* plist, int pdata, int pos)
{
	//추가할 노드 만들기
	Node* newNode = NULL; // NULL 포인터 초기화, 추가되는 노트의 포인터변수
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = pdata;
	newNode->next = NULL;

	if (pos > 1 && pos <= plist->numOfData + 1)
	{
		Node* tmp = plist->head;
		for (int j = 1; j < pos - 1; j++)
		{
			tmp = tmp->next;
		}
		newNode->next = tmp->next;
		tmp->next = newNode;
		plist->tail = newNode;
	}
	else if (pos == 1)
	{
		newNode->next = plist->head;
		plist->head = newNode;
	}

	else
	{
		printf("해당위치에 삽입할 수 없습니다.\n");
	}
	(plist->numOfData)++;
}

/**** 탐색함수 => Search ****/
void Search(Node* Head, int data)
{
	Node* temp = Head->next;
	int n = 1;
	while (temp != NULL)
	{
		Node* next = temp->next;
		if (data == (int)temp->data)
		{
			printf("%d번째 시도만에 인덱스 %d에 있다는 것을 확인. \n", n, n - 1);
		}
		n++;
		temp = next;
	}
}

/**** 제거함수 => Remove ****/
void Remove(List* plist, int pos)
{
	if (pos < 1 && pos <= plist->numOfData + 1)
	{
		printf("해당 위치에 삭제할 값이 없습니다.\n");
		return;
	}
	else
	{
		Node* tmp = plist->head;
		Node* remNode = plist->head;

		if (pos == 1)
		{
			plist->head = plist->head->next;
		}

		else
		{
			for (int k = 1; k < pos - 1; k++)
			{
				tmp = tmp->next;
			}
			remNode = tmp->next;
			tmp->next = tmp->next->next;
		}
		free(remNode);
		(plist->numOfData)--;
	}
}

int main(void)
{
	List* plist = (List*)malloc(sizeof(List));
	plist->cur = NULL;
	plist->head = NULL;
	plist->tail = NULL;

	printf("연결리스트 생성 전 초기화합니다. (Create 구현)\n\n");
	Create(plist); //생성
	Add(plist, 22);
	Add(plist, 2);
	Add(plist, 77);
	Add(plist, 6);
	Add(plist, 43);
	Add(plist, 76);
	Add(plist, 89);

	/**** 데이터 출력 ****/
	printf("입력 받은 데이터의 전체출력! \n");
	if (plist->head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // 첫 번째 데이터 출력

		while (plist->cur->next != NULL)    // 두 번째 이후의 데이터 출력
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}

	}
	printf("\n\n");

	/**** 데이터 6을 탐색(Search) ****/
	printf("연결리스트에서 데이터 6을 찾습니다. (Search 구현)\n");
	Search(plist, 6);
	printf("\n");
	/**** 데이터 출력 ****/
	printf("현재 연결리스트 출력! \n");
	if (plist->head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // 첫 번째 데이터 출력

		while (plist->cur->next != NULL)    // 두 번째 이후의 데이터 출력
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}
	}
	printf("\n\n");

	/**** 머리에 5을 삽입(Insert) ****/
	printf("머리에 노드(데이터 5)을 삽입합니다. (Insert 구현)\n");
	Insert(plist, 5, 1);

	printf("현재 연결리스트 출력! \n");
	if (plist->head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // 첫 번째 데이터 출력

		while (plist->cur->next != NULL)    // 두 번째 이후의 데이터 출력
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}
	}
	printf("\n\n");

	/**** 꼬리에 10을 삽입(Insert) ****/
	printf("꼬리에 노드(데이터 10) 을 삽입합니다. (Insert 구현)\n");
	Insert(plist, 10, 9);

	printf("현재 연결리스트 출력! \n");
	if (plist->head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // 첫 번째 데이터 출력

		while (plist->cur->next != NULL)    // 두 번째 이후의 데이터 출력
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}
	}
	printf("\n\n");

	/**** 데이터 1을 연결리스트 중간에 추가(lnsert) ****/
	printf("특정위치(중간 데이터 1)에 노드 을 삽입합니다. (Insert 구현)\n");
	Insert(plist, 1, 5);

	printf("현재 연결리스트 출력! \n");
	if (plist->head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // 첫 번째 데이터 출력

		while (plist->cur->next != NULL)    // 두 번째 이후의 데이터 출력
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}
	}
	printf("\n\n");

	/**** 머리 노드 삭제(Remove) ****/
	printf("머리 노드를 삭제합니다. (Remove 구현)\n");
	Remove(plist, 1);

	printf("현재 연결리스트 출력! \n");
	if (plist->head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // 첫 번째 데이터 출력

		while (plist->cur->next != NULL)    // 두 번째 이후의 데이터 출력
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}
	}
	printf("\n\n");

	/**** 꼬리 노드 삭제(Remove) ****/
	printf("꼬리 노드를 삭제합니다. (Remove 구현)\n");
	Remove(plist, 9);

	printf("현재 연결리스트 출력! \n");
	if (plist->head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // 첫 번째 데이터 출력

		while (plist->cur->next != NULL)    // 두 번째 이후의 데이터 출력
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}
	}
	printf("\n\n");

	/**** 특정 노드 삭제(Remove) ****/
	printf("특정 노드(아까 추가했던 1)를 삭제합니다. (Remove 구현)\n");
	Remove(plist, 4);

	printf("현재 연결리스트 출력! \n");
	if (plist->head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // 첫 번째 데이터 출력

		while (plist->cur->next != NULL)    // 두 번째 이후의 데이터 출력
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}
	}
	printf("\n\n");

	/**** 메모리의 해제과정 ****/
	printf("모든 노드를 삭제합니다. (Remove 구현)\n");
	if (plist->head == NULL)
	{
		return 0;    // 해제할 노드가 존재하지 않는다.
	}
	else // Remove
	{
		Node* delNode = plist->head;
		Node* delNextNode = plist->head->next;

		printf("%d을(를) 삭제합니다. \n", plist->head->data);
		free(delNode);    // 첫 번째 노드의 삭제

		while (delNextNode != NULL)    // 두 번째 이후의 노드 삭제 위한 반복문
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);    // 두 번째 이후의 노드 삭제
		}
	}
	return 0;
}