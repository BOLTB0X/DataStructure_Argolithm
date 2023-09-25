// 17266 어두운 굴다리
// https://www.acmicpc.net/problem/17266
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int lampHeight[100001];

bool check(int h) {
    for (int i = 0; i< M; ++i) {
        if (i == 0) {
            if (lampHeight[i] - h > 0) return false;
        } 

        if (lampHeight[i] - h > lampHeight[i-1] + h > 0) {
            return false;
        }
        
        if (i == M-1) {
            if (lampHeight[i] + h < N) return false;
        } 
    }
    return true;
}

int binarySearch(void) {
    int result = N;
    int left = 1, mid, right = N;

    while (left <= right) {
        mid = (left+right) / 2;

        if (check(mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main(void) {
    int answer = 0;
    cin >> N >> M;
    
    for (int i = 0; i < M; ++i) {
        cin >> lampHeight[i];
    }

    answer = binarySearch();
    cout << answer << "\n";
    return 0;
}