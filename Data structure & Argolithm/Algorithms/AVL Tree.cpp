//프로그램 설명 : C++로 구현한 AVL 트리입니다.
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 노드 구조체를 정의합니다.
struct nodeAVL
{
    int data;
    struct nodeAVL* left;
    struct nodeAVL* right;
} *root;

// 클래스를 정의합니다.
class classAVL
{
public:
    // 노드의 높이를 반환합니다.
    int height(nodeAVL*);
    // 균형인수(높이의 차이)를 반환합니다.
    int diff(nodeAVL*);
    // RR 회전 함수입니다.
    nodeAVL* rr(nodeAVL*);
    // LL 회전 함수입니다.
    nodeAVL* ll(nodeAVL*);
    // LR 회전 함수입니다.
    nodeAVL* lr(nodeAVL*);
    // RL 회전 함수입니다.
    nodeAVL* rl(nodeAVL*);
    // 트리의 균형을 맞추는 함수입니다.
    nodeAVL* balance(nodeAVL*);
    // AVL 트리에 새로운 원소를 삽입합니다.
    nodeAVL* insert(nodeAVL*, int);
    // 현재의 AVL 트리 내용을 보여주는 함수입니다.
    void display(nodeAVL*, int);
    // AVL 트리를 중위 순회합니다.
    void inorder(nodeAVL*);
    // AVL 트리를 전위 순회합니다.
    void preorder(nodeAVL*);
    // AVL 트리를 후위 순회합니다.
    void postorder(nodeAVL*);
    // classAVL의 생성자입니다.
    classAVL()
    {
        root = NULL;
    }
};

int main(void)
{
    int choice, item;
    classAVL AVL;
    while (1)
    {
        cout << "\n----------------------------" << endl;
        cout << "    C++로 구현한 AVL 트리" << endl;
        cout << "----------------------------" << endl;
        cout << "1. 원소를 삽입할래요." << endl;
        cout << "2. AVL 트리를 보여주세요." << endl;
        cout << "3. 중위 순회를 하고싶어요." << endl;
        cout << "4. 전위 순회를 하고싶어요." << endl;
        cout << "5. 후위 순회를 하고싶어요." << endl;
        cout << "6. 프로그램을 종료할래요." << endl;
        cout << "당신의 선택을 입력하세요 : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "삽입할 정수를 입력하세요 : ";
            cin >> item;
            root = AVL.insert(root, item);
        case 2:
            if (root == NULL)
            {
                cout << "현재 트리가 비었습니다." << endl;
                continue;
            }
            cout << "[ AVL 트리 출력 ]" << endl;
            AVL.display(root, 1);
            break;
        case 3:
            cout << "[ 중위 순회 ]" << endl;
            AVL.inorder(root);
            cout << endl;
            break;
        case 4:
            cout << "[ 전위 순회 ]" << endl;
            AVL.preorder(root);
            cout << endl;
            break;
        case 5:
            cout << "[ 후위 순회 ]" << endl;
            AVL.postorder(root);
            cout << endl;
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "잘못된 입력입니다." << endl;
        }
    }
    return 0;
}

// AVL 트리의 높이를 출력합니다.
int classAVL::height(nodeAVL* temp)
{
    int h = 0;
    if (temp != NULL)
    {
        // 재귀적으로 왼쪽 혹은 오른쪽으로 검색합니다.
        int left = height(temp->left);
        int right = height(temp->right);
        int maxHeight = max(left, right);
        h = maxHeight + 1;
    }
    return h;
}

// 균형인수(높이의 차이)를 반환합니다.
int classAVL::diff(nodeAVL* temp)
{
    // 왼쪽 자식의 높이와 오른쪽 자식의 높이 차이를 반환합니다.
    int left = height(temp->left);
    int right = height(temp->right);
    int factor = left - right;
    return factor;
}

// RR 회전 함수입니다.
nodeAVL* classAVL::rr(nodeAVL* parent)
{
    // 말이 회전이지 그냥 부모 노드의 오른쪽 자식노드와 데이터를 교환하는 것입니다.
    nodeAVL* temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

// ll 회전 함수입니다.
nodeAVL* classAVL::ll(nodeAVL* parent)
{
    // RR 회전과 반대입니다.
    nodeAVL* temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

// LR 회전 함수입니다.
nodeAVL* classAVL::lr(nodeAVL* parent)
{
    // LR 회전은 왼쪽 자식을 기준으로 RR, 본인을 기준으로 LL회전합니다.
    nodeAVL* temp;
    temp = parent->left;
    parent->left = rr(temp);
    return ll(parent);
}

// RL 회전 함수입니다.
nodeAVL* classAVL::rl(nodeAVL* parent)
{
    // LR 회전과 반대입니다.
    nodeAVL* temp;
    temp = parent->right;
    parent->right = ll(temp);
    return rr(parent);
}

// AVL 트리의 균형을 맞추는 함수입니다.
nodeAVL* classAVL::balance(nodeAVL* temp)
{
    int factor = diff(temp);
    // 왼쪽 서브트리쪽으로 삽입이 되어 균형이 깨진 경우입니다.
    if (factor > 1)
    {
        // 그 왼쪽 자식노드에 문제가 발생했습니다.
        if (diff(temp->left) > 0)
        {
            temp = ll(temp);
        }
        // 그 오른쪽 자식 노드에 문제가 발생했습니다.
        else
        {
            temp = lr(temp);
        }
    }
    else if (factor < -1)
    {
        if (diff(temp->right) > 0)
        {
            temp = rl(temp);
        }
        else
        {
            temp = rr(temp);
        }
    }
    return temp;
}

// 트리에 원소를 삽입하는 함수입니다.
nodeAVL* classAVL::insert(nodeAVL* root, int value)
{
    // 현재 트리가 비었을 때
    if (root == NULL)
    {
        root = new nodeAVL;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance(root);
    }
    // 크거나 같은 경우 오른쪽 서브트리에 삽입합니다.
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance(root);
    }
    return root;
}

void classAVL::display(nodeAVL* ptr, int level)
{
    int i;
    // 현재 트리가 비어있지 않은 경우입니다.
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        // 현재 루트 노드인 경우입니다.
        if (ptr == root)
        {
            cout << "Root -> ";
        }
        // i가 현레벨보다 낮고 루트가 아닌 경우일 때까지 입니다.
        for (i = 0; i < level && ptr != root; i++)
        {
            cout << "        ";
        }
        // 자신의 위치에 데이터를 출력합니다.
        cout << ptr->data;
        // 왼쪽 노드도 출력해줍니다.
        display(ptr->left, level + 1);
    }
}

/* 트리를 순회하는 세 가지 함수입니다. */
void classAVL::inorder(nodeAVL* tree)
{
    if (tree == NULL)
        return;
    inorder(tree->left);
    cout << tree->data << "  ";
    inorder(tree->right);
}
void classAVL::preorder(nodeAVL* tree)
{
    if (tree == NULL)
        return;
    cout << tree->data << "  ";
    inorder(tree->left);
    inorder(tree->right);
}
void classAVL::postorder(nodeAVL* tree)
{
    if (tree == NULL)
        return;
    inorder(tree->left);
    inorder(tree->right);
    cout << tree->data << "  ";
}