#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 찾고자 하는 값 이상이 처음 나타나는 위치
int lower_binary(int* arr, int target, int start, int end) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid] >= target)
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}

int main(void) {
	int arr[5] = { 1,2,3,4,5 };
	vector<int> v = { 1,2,3,4,5,5,5 };
	//찾으려는 key값보다 같거나 큰 숫자가 배열에 몇번째(idx)에서 처음 등장하는 지
	//배열 OR 벡터는 오름차순이여야함
	cout << lower_bound(arr, arr + 5, 5) - arr << '\n';
	cout << lower_bound(v.begin(), v.end(), 5) - v.begin() << '\n';
	cout << lower_binary(arr,4,0,4); << '\n';
	return 0;
}
