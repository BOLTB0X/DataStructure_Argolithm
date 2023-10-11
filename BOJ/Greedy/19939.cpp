// 19939 박 터뜨리기
// https://www.acmicpc.net/problem/19939
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K, answer = 1001;
    cin >> N >> K;
    // 연속적인 케이스: k-1
    //ex. 6 3: 1 2 3 -> 2
    //ex. 9 3: 2 3 4 -> 2
    //ex. 10 4: 1 2 3 4 -> 3

    // 연속적이지 않은 케이스: k
    //ex. 7 3: 1 2 4
    //ex. 11 3: 2 4 5
    //ex. 11 4: 1 2 3 5
    
    int basketSum = 1;
    for (int i = 2; i <= K; ++i)
    {
        basketSum += i;
    }

    N -= basketSum;
    if (N >= 0) 
    {
        if (N % K == 0)
        {
            answer = K-1;
        } else {
            answer = K;
        }
    } else 
    {
        answer = -1;
    }
    
    cout << answer << '\n';

    return 0;
}