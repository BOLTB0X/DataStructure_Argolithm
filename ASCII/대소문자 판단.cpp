#include <iostream>

using namespace std;

void encode(char ch)
{
    if ('a' <= ch && ch <= 'z') {
        cout << "�ҹ����̸�, �ƽ�Ű �ڵ尪�� " << ch << " �Դϴ�. \n";
    }
    else if ('A' <= ch && ch <= 'Z') {
        cout << "�빮���̸� �ƽ�Ű �ڵ尪�� " << ch << " �Դϴ�. \n";
    }
    else {
        cout << "Ư�������̰ų� ���ڿ���.\n";
    }
    return;
}

int main(void) {
    char ch = 'a';
    encode(ch);
    return 0;
}