#include <iostream> //입출력 표준 라이브러리
#include <string>
using namespace std;

int main(void) {
	int i = 123;
	string s = to_string(i);
	cout << "정수 -> 문자열: " << s << endl;
	s = "456";
	cout << "문자열 -> 정수: " << i << endl;
	system("pause");
	return 0;
}