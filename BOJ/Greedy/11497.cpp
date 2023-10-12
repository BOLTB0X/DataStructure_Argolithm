// 11497 통나무 건너뛰기
// https://www.acmicpc.net/problem/11497
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mx(int a, int b) {
    return a > b ? a : b;
}

int as(int a) {
    return a < 0 ? -a : a;
}

int solution(int N, vector<int> woods) {
    int answer = 0;
    // 2, 4, 5, 7, 9
    //  2  3  5  2 -> 5
    //  2  1  3  5 -> 5
    //  3  1  2  4 -> 4
    //  5  3  2  2 -> 5
    //  7  5  4  2 -> 7
    sort(woods.begin(), woods.end());
    vector<int> tmpWoods(N, 0);
    int left = 0, right = N-1;

    for (int i = 0; i < N; ++i)
    {
        if (i % 2 == 0) 
        {
            tmpWoods[left++] = woods[i];
        } else 
        {
            tmpWoods[right--] = woods[i];
        }
    }

    for (int i = 1; i < N; ++i)
    {
        answer = mx(answer, as(tmpWoods[i]-tmpWoods[i-1]));
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    vector<int> woods;

    cin >> T;
    while (T--)
    {
        cin >> N;
        woods = vector<int> (N, 0);
        for (int i = 0; i < N; ++i)
        {
            cin >> woods[i];
        }

        cout << solution(N, woods) << '\n';
    }
    

    return 0;
}