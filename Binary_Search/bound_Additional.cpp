#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 오름차순 정렬된 자료에서 특정 범위에 속하는 숫자들이 
// 몇 개 있는지 탐색하고자 할 때
int main(void) {
	int arr[11] = { 1,3,5,5,7,8,8,10,10,11,13 };
	vector<int> v = { 1,3,5,5,7,8,8,10,10,11,13 };
	//이진 탐색 기반의 lower, upper_bound를 사용하여 
	// ==>> O(logN)으로 탐색 가능 
	// O(N)이 불가능 할 때 유용하게 사용 가능.
	cout << "3의 갯수 : " << upper_bound(v.begin(), v.end(), 5) - lower_bound(v.begin(), v.end(), 5) << '\n';
	return 0;
}