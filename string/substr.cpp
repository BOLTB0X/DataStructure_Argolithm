#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string st = "s1tring";
	//substr startidx는 0으로 초기화 되어있음 --> 시작,cnt로 기억
	cout << st.substr(0, 2) << '\n'; // s1
	cout << st.substr(2, 1) << '\n'; // t
	cout << st.substr(4, 3) << '\n'; // ing
	cout << st.substr(5, 2) << '\n'; // ng subtr(5, 2) 이면 5번부터 2개
	cout << st.substr(1) << '\n'; //s
	return 0;
}
