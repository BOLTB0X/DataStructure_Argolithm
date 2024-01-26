#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 찾고자 하는 값보다 큰 값이 처음으로 나타나는 위치
int upper_binary(int* arr, int target, int start, int end) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid] > target)
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}

int main(void) {
	int arr[5] = { 1,2,3,4,5 };
	vector<int> v = { 1,2,3,4,5,5,5 };
	//찾으려는 key값을 초과하는 숫자가 배열에 몇번째(idx)에서 처음 등장하는 지
	//배열 OR 벡터는 오름차순이여야함
	cout << upper_bound(arr, arr + 5, 3) - arr << '\n';
	cout << upper_bound(v.begin(), v.end(), 3) - v.begin() << '\n';
	cout << upper_binary(arr,3,0,4) << '\n;
	return 0;
}
