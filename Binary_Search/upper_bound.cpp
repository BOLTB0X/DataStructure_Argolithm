#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int arr[5] = { 1,2,3,4,5 };
	vector<int> v = { 1,2,3,4,5,5,5 };
	//찾으려는 key값을 초과하는 숫자가 배열에 몇번째(idx)에서 처음 등장하는 지
	//배열 OR 벡터는 오름차순이여야함
	cout << upper_bound(arr, arr + 5, 3) - arr << '\n';
	cout << upper_bound(v.begin(), v.end(), 3) - v.begin() << '\n';
	return 0;
}