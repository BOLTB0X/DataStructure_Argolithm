// 1920 수 찾기
// https://www.acmicpc.net/problem/1920
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int binarySearch(int *arr, int target, int left, int right) {
    while (left <= right) {
        int mid = (left+right) / 2;
        if (arr[mid] == target) return 1;
        else if (arr[mid] > target) right = mid-1;
        else left = mid + 1;
    }
    return 0;
}

int main(void) {
    int arr[100001] = {0, };
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + N);

    scanf("%d", &M);
    int t;
    for (int i = 0; i < M; ++i) {
        scanf("%d", &t);

        int res = binarySearch(arr, t, 0, N-1);
        printf("%d\n", res);
    }

    return 0;
}