#include <iostream>
using namespace std;

int binary_search(int* arr, int target, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		//Ÿ���� �� �߰����� ���
		if (arr[mid] == target) {
			return mid;
		}
		//Ÿ���� �߰������� ���� ���
		//�� ��������
		else if (arr[mid] > target)
			end = mid - 1;
		//Ÿ���� �߰������� ū ���
		//�� ����������
		else
			start = mid + 1;
	}
	//��ã�� ���
	return -1;
}