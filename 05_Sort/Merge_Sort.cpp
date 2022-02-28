#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v(1000001, 0);
int *tmp_v;

//병합하며 정렬 
void merge(int left, int right) {
	int mid = (left + right) / 2;
	
	int i = left;
	int j = mid + 1;
	int k = left;
	
	while(i <= mid && j <= right) {
		if (v[i] <= v[j])
			tmp_v[k++] = v[i++];
		else
			tmp_v[k++] = v[j++];	
	} 
	
	if(i > mid) { 
		for(int t = j; t<= right; t++) 
			tmp_v[k++] = v[t]; 
	}
	
	else { 
		for(int t = i; t <=right; t++) 
			tmp_v[k++] = v[t];
	}


	for (int i = left; i <= right; ++i)
		v[i] = tmp_v[i];
		
	return;
}

// 분할을 재귀적으로 호출
void partition(int left, int right) {
	int mid;
	
	if (left < right) {
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
	
	return;
}

int main(void) {
	cin >> n;
	
	tmp_v = new int[n];
	for (int i=0; i <n;++i)
		cin >> v[i];
		
	partition(0, n-1);
	for (int i=0; i <n;++i)
		cout << v[i] << ' ';
	
	return 0;
}

