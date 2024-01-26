#include <iostream>
#define M 5
using namespace std;
//프로그램 설명 : C++로 구현한 B-Tree
// BTree의 노드 구조체를 선언

struct BTreeNode // Public과 동일한 구조체 선언
{
    int* data; // 노드에 들어갈 자료의 배열
    BTreeNode** childPtr; // 노드 포인트의 배열
    bool leaf; // 리프 노드인지 확인
    int n; // 자료의 개수를 의미
}*root = NULL, * np = NULL, * x = NULL;

// 노드를 초기화하는 함수
BTreeNode* init()
{
    int i;
    np = new BTreeNode; // 객체를 할당
    np->data = new int[M]; // M개까지의 데이터를 가질 수 있음
    np->childPtr = new BTreeNode * [6]; // M + 1개의 자식 노드
    np->leaf = true; // 기본적으로 리프 노드
    np->n = 0; // 자료의 개수는 0개
    for (i = 0; i < 6; i++)
    {
        np->childPtr[i] = NULL; // 각각의 자식 노드를 초기화
    }
    return np;
}

// 현재 트리를 보여주는 순회 함수입니다.
void traverse(BTreeNode* p)
{
    cout << endl;
    int i;
    // 즉, 첫번째 자식 노드부터 가장 마지막 자식 노드까지 전부 밑으로 내려가는 것입니다.
    for (i = 0; i < p->n; i++)
    {
        // 리프 노드가 아니라면 더 밑으로 내려갑니다.
        if (p->leaf == false)
        {
            traverse(p->childPtr[i]);
        }
        // 데이터를 출력합니다.
        cout << " " << p->data[i];
    }
    // 리프 노드가 아니라면 더 밑으로 내려갑니다.
    if (p->leaf == false)
    {
        traverse(p->childPtr[i]);
    }
    cout << endl;
}

// n개 존재하는 데이터 배열 데이터를 정렬하는 함수입니다.
void sort(int* p, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (p[i] > p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// 자식을 분할하는 함수입니다.
int splitChild(BTreeNode* x, int i)
{

    // x노드를 분할하여 np1과 np3을 할당합니다.
    int j, mid;
    BTreeNode* np1, * np3, * y;

    /*
     분할된 형태는 다음과 같습니다.
     x -> 왼쪽으로 가고
     np3 -> 그 오른쪽으로 가고
     np1 -> x와 np3의 부모 노드가 됩니다.
    */

    np3 = init();
    np3->leaf = true;

    // x의 부모 노드가 없어 새롭게 부모 노드를 만들어주는 경우입니다.
    if (i == -1)
    {

        // M의 중간값을 기준으로 분할합니다.
        mid = x->data[M / 2];
        x->data[M / 2] = 0;
        x->n--;
        np1 = init();

        // np1는 부모노드이므로 리프 노드가 아닙니다.
        np1->leaf = false;
        x->leaf = true;
        for (j = M / 2 + 1; j < M; j++)
        {

            // np3는 x의 오른쪽 부분 노드를 가져갑니다.
            np3->data[j - (M / 2 + 1)] = x->data[j];
            np3->childPtr[j - (M / 2 + 1)] = x->childPtr[j];
            np3->n++;

            // x는 반 쪼개서 왼쪽 부분 노드만 가지고 갑니다.
            x->data[j] = 0;
            x->n--;
        }

        // x의 모든 자식 노드를 NULL로 만듭니다.
        for (j = 0; j < M + 1; j++)
        {
            x->childPtr[j] = NULL;
        }
        np1->data[0] = mid;
        np1->childPtr[np1->n] = x;
        np1->childPtr[np1->n + 1] = np3;
        np1->n++;

        // 루트 노드로 설정해줍니다.
        root = np1;
    }

    // 이미 부모 노드가 있는 경우입니다.
    else
    {
        y = x->childPtr[i];
        mid = y->data[M / 2];
        y->data[M / 2] = 0;
        y->n--;
        for (j = M / 2 + 1; j < M; j++)
        {

            // np3은 x의 오른쪽 자식 부분만 가져갑니다.
            np3->data[j - (M / 2 + 1)] = y->data[j];
            np3->n++;
            y->data[j] = 0;
            y->n--;
        }
        x->childPtr[i + 1] = y;
        x->childPtr[i + 1] = np3;
    }
    return mid;
}

// a라는 원소를 삽입하는 함수입니다.
void insert(int a)
{
    int i, temp;
    x = root;

    // 만약에 루트 노드가 NULL이라면
    if (x == NULL)
    {
        root = init();
        x = root;
    }

    // 루트 노드가 NULL이 아니라면
    else
    {

        // 현재 리프노드이고 크기가 꽉찼다면
        if (x->leaf == true && x->n == M)
        {
            temp = splitChild(x, -1);
            x = root;

            // 값을 이동하며 삽입될 자리를 찾습니다.
            for (i = 0; i < (x->n); i++)
            {
                if ((a > x->data[i]) && (a < x->data[i + 1]))
                {
                    i++;
                    break;
                }
                else if (a < x->data[0])
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            x = x->childPtr[i];
        }

        // 리프노드가 아닐 때입니다.
        else
        {

            // 리프 노드까지 이동합니다.
            while (x->leaf == false)
            {
                for (i = 0; i < (x->n); i++)
                {
                    if ((a > x->data[i]) && (a < x->data[i + 1]))
                    {
                        i++;
                        break;
                    }
                    else if (a < x->data[0])
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }

                // 리프 노드 위에서도 만약에 최대치를 넘으면 분할해줍니다.
                if ((x->childPtr[i])->n == M)
                {
                    temp = splitChild(x, i);
                    x->data[x->n] = temp;
                    x->n++;
                    continue;
                }
                else
                {
                    x = x->childPtr[i];
                }
            }
        }
    }
    x->data[x->n] = a;
    sort(x->data, x->n);
    x->n++;
}

int main(void)
{
    int i, n, t;
    cout << "삽입할 원소의 개수를 입력하세요 : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "원소를 입력하세요 : ";
        cin >> t;
        insert(t);
    }
    cout << "트리를 순회합니다." << endl;
    traverse(root);
    return 0;
}