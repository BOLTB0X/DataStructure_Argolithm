#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int arr[5] = { 1,2,3,4,5 };
	vector<int> v = { 1,2,3,4,5,5,5 };
	//ã������ key������ ���ų� ū ���ڰ� �迭�� ���°(idx)���� ó�� �����ϴ� ��
	//�迭 OR ���ʹ� ���������̿�����
	cout << lower_bound(arr, arr + 5, 5) - arr << '\n';
	cout << lower_bound(v.begin(), v.end(), 5) - v.begin() << '\n';
	return 0;
}