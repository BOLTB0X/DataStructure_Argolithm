#include <iostream>
using namespace std;

int binary_search(int* arr, int target, int start, int end) {
	//�� ã�� ���
	if (start > end)
		return -1;
	int mid = (start + mid) / 2;
	//Ÿ���� �߰����� ��� �ε��� ��ȯ
	if (arr[mid] == target)
		return mid;
	//Ÿ���� �߰������� ���� ��� ==> ��������
	else if (arr[mid] > target)
		return binary_search(arr, target, start, mid - 1);
	//Ÿ���� ū ��� ==> ����������
	else
		return binary_search(arr, target, mid + 1, end);
}