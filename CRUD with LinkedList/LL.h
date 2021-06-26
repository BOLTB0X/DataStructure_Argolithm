#ifndef __LL_H__
#define __LL_H__

typedef struct _list  // 구조체 선언
{
	struct _node* cur;  //위치참조 포인터변수
	struct _node* head; //머리를 나타내는 포인터 변수
	struct _node* tail; //꼬리를 나타내는 포인터 변수
	int numOfData;
} List;


typedef struct _node      // 기본 노드  
{
	int data;             // 데이터 변수
	struct _node* next;  // 연결 도구
} Node;

void Create(List* plist); 
void Add(List* plist, int pdata);
void Insert(List* plist, int pdata, int pos);
void Search(Node* Head, int data);
void Remove(List* plist, int pos);

#endif