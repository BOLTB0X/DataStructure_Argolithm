#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �������� ���ĵ� �ڷῡ�� Ư�� ������ ���ϴ� ���ڵ��� 
// �� �� �ִ��� Ž���ϰ��� �� ��
int main(void) {
	int arr[11] = { 1,3,5,5,7,8,8,10,10,11,13 };
	vector<int> v = { 1,3,5,5,7,8,8,10,10,11,13 };
	//���� Ž�� ����� lower, upper_bound�� ����Ͽ� 
	// ==>> O(logN)���� Ž�� ���� 
	// O(N)�� �Ұ��� �� �� �����ϰ� ��� ����.
	cout << "3�� ���� : " << upper_bound(v.begin(), v.end(), 5) - lower_bound(v.begin(), v.end(), 5) << '\n';
	return 0;
}