#include <iostream>

using namespace std;;

void merge(int n, int* arr, int start, int end) {
	int* sorted = new int[n]; // 임시

	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = start;

	while (i <= mid && j <= end) {
		if (arr[i] < arr[j])
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}

	if (i > mid) {
		for (int a = j; a <= end; ++a)
			sorted[k++] = arr[a];
	}

	else {
		for (int a = i; a <= mid; ++a)
			sorted[k++] = arr[a];
	}

	for (int a = start; a <= end; ++a)
		arr[a] = sorted[a];

	delete[] sorted;
	return;
}

void merge_Sort(int n, int* arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_Sort(n, arr, start, mid);
		merge_Sort(n, arr, mid + 1, end);
		merge(n, arr, start, end);
	}
	return;
}

int main(void) {
	int n;
	int* arr;

	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	merge_Sort(n, arr, 0, n - 1);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';

	delete[] arr;
	return 0;
}

