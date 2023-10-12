// 2303 숫자 게임
// https://www.acmicpc.net/problem/2303
#include <iostream>
#include <vector>

using namespace std;

int mx(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, answer = 0;
    int arr[1001][5];

    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> arr[i][j];
        }
    }

    vector<int> number(N, 0);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 3; ++j)
            for (int k = j+1; k < 4; ++k)
                for (int l = k+1; l < 5; ++l)
                {
                    int tmp = arr[i][j]+arr[i][k]+arr[i][l];
                    //cout << tmp << '\n';
                    number[i] = mx(number[i], tmp % 10);
                }
    }


    for (int i = 0; i < N; ++i)
    {
        if (number[i] >= number[answer]) {
            answer = i;
        } 
    }

    cout << answer + 1;
    return 0;
}