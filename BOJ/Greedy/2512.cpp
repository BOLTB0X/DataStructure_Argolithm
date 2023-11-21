// 2512 예산
// https://www.acmicpc.net/problem/2512
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N, int target, vector<int> budgets) {
    int answer = 0;

    // 110 120 140 150에서 상한가를 찾아야함

    sort(budgets.begin(), budgets.end());
    int left = 0, right = budgets.back();
    int tot = 0;

    while (left <= right)
    {
        int mid = (left+right) / 2;
        int idx = lower_bound(budgets.begin(), budgets.end(), mid) - budgets.begin();
        tot = 0;
            
        for (int i = 0; i < idx; ++i) tot += budgets[i];
        tot += (mid * (N-idx));

        if (tot <= target) 
        {
            answer = mid;
            left = mid + 1;
        } else
        {
            right = mid - 1;
        }
    }
    
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, target;
    vector<int> budgets;

    cin >> N;
    budgets.resize(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> budgets[i];
    }

    cin >> target;

    cout << solution(N, target, budgets);
    return 0;
}