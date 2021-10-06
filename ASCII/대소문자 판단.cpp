#include <iostream>

using namespace std;

void encode(char ch)
{
    if ('a' <= ch && ch <= 'z') {
        cout << "소문자이며, 아스키 코드값은 " << ch << " 입니다. \n";
    }
    else if ('A' <= ch && ch <= 'Z') {
        cout << "대문자이며 아스키 코드값은 " << ch << " 입니다. \n";
    }
    else {
        cout << "특수문자이거나 숫자에요.\n";
    }
    return;
}

int main(void) {
    char ch = 'a';
    encode(ch);
    return 0;
}