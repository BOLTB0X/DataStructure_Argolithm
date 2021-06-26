#include <stdio.h>
#include <stdlib.h>
#include "LL.h"


/**** �����Լ�(���� �ʱ�ȭ) => Create ****/
void Create(List* plist)
{
	Node* head = NULL;      // NULL ������ �ʱ�ȭ, ����Ʈ �Ӹ��� ����Ű�� �����ͺ���
	Node* tail = NULL;      // NULL ������ �ʱ�ȭ, ����Ʈ ������ ����Ű�� �����ͺ���
	Node* cur = NULL;       // NULL ������ �ʱ�ȭ, ����� �������� ��ȸ�ϴ� �����ͺ���
	plist->numOfData = 0;   // ������ ��
}
/***�߰��Լ�(������ �߰�)*****/
void Add(List* plist, int pdata)
{
	Node* newNode = NULL; // NULL ������ �ʱ�ȭ, �߰��Ǵ� ��Ʈ�� �����ͺ���
	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = pdata;
	newNode->next = NULL;
	if (plist->head == NULL && plist->tail == NULL) //�Ӹ� ������ ������� ���
		plist->head = plist->tail = newNode;
	else
	{
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	(plist->numOfData)++;
}
/**** �����Լ� => Insert ****/
void Insert(List* plist, int pdata, int pos)
{
	//�߰��� ��� �����
	Node* newNode = NULL; // NULL ������ �ʱ�ȭ, �߰��Ǵ� ��Ʈ�� �����ͺ���
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
		printf("�ش���ġ�� ������ �� �����ϴ�.\n");
	}
	(plist->numOfData)++;
}

/**** Ž���Լ� => Search ****/
void Search(Node* Head, int data)
{
	Node* temp = Head->next;
	int n = 1;
	while (temp != NULL)
	{
		Node* next = temp->next;
		if (data == (int)temp->data)
		{
			printf("%d��° �õ����� �ε��� %d�� �ִٴ� ���� Ȯ��. \n", n, n - 1);
		}
		n++;
		temp = next;
	}
}

/**** �����Լ� => Remove ****/
void Remove(List* plist, int pos)
{
	if (pos < 1 && pos <= plist->numOfData + 1)
	{
		printf("�ش� ��ġ�� ������ ���� �����ϴ�.\n");
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

	printf("���Ḯ��Ʈ ���� �� �ʱ�ȭ�մϴ�. (Create ����)\n\n");
	Create(plist); //����
	Add(plist, 22);
	Add(plist, 2);
	Add(plist, 77);
	Add(plist, 6);
	Add(plist, 43);
	Add(plist, 76);
	Add(plist, 89);

	/**** ������ ��� ****/
	printf("�Է� ���� �������� ��ü���! \n");
	if (plist->head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // ù ��° ������ ���

		while (plist->cur->next != NULL)    // �� ��° ������ ������ ���
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}

	}
	printf("\n\n");

	/**** ������ 6�� Ž��(Search) ****/
	printf("���Ḯ��Ʈ���� ������ 6�� ã���ϴ�. (Search ����)\n");
	Search(plist, 6);
	printf("\n");
	/**** ������ ��� ****/
	printf("���� ���Ḯ��Ʈ ���! \n");
	if (plist->head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // ù ��° ������ ���

		while (plist->cur->next != NULL)    // �� ��° ������ ������ ���
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}
	}
	printf("\n\n");

	/**** �Ӹ��� 5�� ����(Insert) ****/
	printf("�Ӹ��� ���(������ 5)�� �����մϴ�. (Insert ����)\n");
	Insert(plist, 5, 1);

	printf("���� ���Ḯ��Ʈ ���! \n");
	if (plist->head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // ù ��° ������ ���

		while (plist->cur->next != NULL)    // �� ��° ������ ������ ���
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}
	}
	printf("\n\n");

	/**** ������ 10�� ����(Insert) ****/
	printf("������ ���(������ 10) �� �����մϴ�. (Insert ����)\n");
	Insert(plist, 10, 9);

	printf("���� ���Ḯ��Ʈ ���! \n");
	if (plist->head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // ù ��° ������ ���

		while (plist->cur->next != NULL)    // �� ��° ������ ������ ���
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}
	}
	printf("\n\n");

	/**** ������ 1�� ���Ḯ��Ʈ �߰��� �߰�(lnsert) ****/
	printf("Ư����ġ(�߰� ������ 1)�� ��� �� �����մϴ�. (Insert ����)\n");
	Insert(plist, 1, 5);

	printf("���� ���Ḯ��Ʈ ���! \n");
	if (plist->head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // ù ��° ������ ���

		while (plist->cur->next != NULL)    // �� ��° ������ ������ ���
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}
	}
	printf("\n\n");

	/**** �Ӹ� ��� ����(Remove) ****/
	printf("�Ӹ� ��带 �����մϴ�. (Remove ����)\n");
	Remove(plist, 1);

	printf("���� ���Ḯ��Ʈ ���! \n");
	if (plist->head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // ù ��° ������ ���

		while (plist->cur->next != NULL)    // �� ��° ������ ������ ���
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}
	}
	printf("\n\n");

	/**** ���� ��� ����(Remove) ****/
	printf("���� ��带 �����մϴ�. (Remove ����)\n");
	Remove(plist, 9);

	printf("���� ���Ḯ��Ʈ ���! \n");
	if (plist->head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // ù ��° ������ ���

		while (plist->cur->next != NULL)    // �� ��° ������ ������ ���
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}
	}
	printf("\n\n");

	/**** Ư�� ��� ����(Remove) ****/
	printf("Ư�� ���(�Ʊ� �߰��ߴ� 1)�� �����մϴ�. (Remove ����)\n");
	Remove(plist, 4);

	printf("���� ���Ḯ��Ʈ ���! \n");
	if (plist->head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else
	{
		plist->cur = plist->head;
		printf("%d  ", plist->cur->data);   // ù ��° ������ ���

		while (plist->cur->next != NULL)    // �� ��° ������ ������ ���
		{
			plist->cur = plist->cur->next;
			printf("%d  ", plist->cur->data);
		}
	}
	printf("\n\n");

	/**** �޸��� �������� ****/
	printf("��� ��带 �����մϴ�. (Remove ����)\n");
	if (plist->head == NULL)
	{
		return 0;    // ������ ��尡 �������� �ʴ´�.
	}
	else // Remove
	{
		Node* delNode = plist->head;
		Node* delNextNode = plist->head->next;

		printf("%d��(��) �����մϴ�. \n", plist->head->data);
		free(delNode);    // ù ��° ����� ����

		while (delNextNode != NULL)    // �� ��° ������ ��� ���� ���� �ݺ���
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d��(��) �����մϴ�. \n", delNode->data);
			free(delNode);    // �� ��° ������ ��� ����
		}
	}
	return 0;
}