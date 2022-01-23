#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string st = "s1tring";
	//substr startidx는 0으로 초기화 되어있음 --> 시작,cnt로 기억
	cout << st.substr(0, 2) << '\n';
	cout << st.substr(2,0) << '\n'; //2부터 0까지
	cout << st.substr(1) << '\n';
	return 0;
}
