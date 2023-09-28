// 10798 세로읽기
// https://www.acmicpc.net/problem/10798
#include <iostream>
#include <string>

using namespace std;

string arr[5];
char answer[15][5];

int main(void)
{
    for (int i = 0; i < 5; ++i)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 15; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            answer[i][j] = ' ';
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < arr[i].size(); ++j)
        {
            answer[j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < 15; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (answer[i][j] == ' ') continue;
            cout << answer[i][j];
        }
    }
    cout << '\n';

    return  0;
}