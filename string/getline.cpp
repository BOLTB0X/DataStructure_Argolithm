#include <iostream> 
#include <string>
using namespace std;
//공백을 포함하여 한 줄을 모두 문자열 형태로 입력받고자 한다면
//getline()함수 이용
int main(void) {
	string input;
	getline(cin, input);
	for (int i = 0; i < input.size(); i++) {
		cout << input[i] << '\n';
	}
	system("pause");
	return 0;
}