// 5597 과제 안 내신 분..?
// https://www.acmicpc.net/problem/5597
#include <iostream>

using namespace std;
bool student_check[31];

int main(void) {
	int student;

	for (int i = 0; i < 28; i++) {
		cin >> student;
		student_check[student] = true;
	}

	for (int i = 1; i <= 30; i++) {
		if (!student_check[i]) {
			cout << i << '\n';
		}
	}
	return 0;
}