// 2075 N번 째 큰수
// https://www.acmicpc.net/problem/2075
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int arr[2250010];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, cmp> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            pq.push(input);
        }

        while (pq.size() > n) {
            pq.pop();
        }
    }

    cout << pq.top() << endl;
    return 0;
}