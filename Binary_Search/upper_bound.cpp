#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int arr[5] = { 1,2,3,4,5 };
	vector<int> v = { 1,2,3,4,5,5,5 };
	//ã������ key���� �ʰ��ϴ� ���ڰ� �迭�� ���°(idx)���� ó�� �����ϴ� ��
	//�迭 OR ���ʹ� ���������̿�����
	cout << upper_bound(arr, arr + 5, 3) - arr << '\n';
	cout << upper_bound(v.begin(), v.end(), 3) - v.begin() << '\n';
	return 0;
}