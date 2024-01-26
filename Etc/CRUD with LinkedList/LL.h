#ifndef __LL_H__
#define __LL_H__

typedef struct _list  // ����ü ����
{
	struct _node* cur;  //��ġ���� �����ͺ���
	struct _node* head; //�Ӹ��� ��Ÿ���� ������ ����
	struct _node* tail; //������ ��Ÿ���� ������ ����
	int numOfData;
} List;


typedef struct _node      // �⺻ ���  
{
	int data;             // ������ ����
	struct _node* next;  // ���� ����
} Node;

void Create(List* plist); 
void Add(List* plist, int pdata);
void Insert(List* plist, int pdata, int pos);
void Search(Node* Head, int data);
void Remove(List* plist, int pos);

#endif