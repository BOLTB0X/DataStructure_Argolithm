// 2839 설탕 배달
// https://www.acmicpc.net/problem/2839
#include <iostream>

using namespace std;

int main(void)
{
    int N, answer = 0;

    cin >> N;

    while (1)
    {
        if (N%5 == 0) 
        {
            answer += (N/5);
            break;
        }

        N -= 3;

        if (N < 0) 
        {
            answer = -1;
            break;
        } else {
            answer++;
        }
    }
    
    
    cout << answer << '\n';

    return 0;
}