#include <iostream> 
#include <string>
using namespace std;
//������ �����Ͽ� �� ���� ��� ���ڿ� ���·� �Է¹ް��� �Ѵٸ�
//getline()�Լ� �̿�
int main(void) {
	string input;
	getline(cin, input);
	for (int i = 0; i < input.size(); i++) {
		cout << input[i] << '\n';
	}
	system("pause");
	return 0;
}