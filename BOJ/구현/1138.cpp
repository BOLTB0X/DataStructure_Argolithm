// 한 줄로 서기
// https://www.acmicpc.net/problem/1138
#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[11];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int answer[11];

    cin >> N; 
    for (int i = 0; i<N; ++i)
    {
        cin >> arr[i];
    }

    memset(answer, 0, sizeof(answer));
    for (int i = 0; i < N; ++i)
    {
        int cnt = 0; // 빈 좌석 확인
        for (int j = 0; j < N; ++j)
        {
            if (!answer[j])
            {
                if (arr[i] == cnt)
                {
                    answer[j] = i+1;
                    break;
                }

                cnt++;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}