// 2490 윷놀이
// https://www.acmicpc.net/problem/2490
#include <iostream>

using namespace std;

int main(void) {
    int arr[4];

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin >> arr[j];
        }

        int front = 0, back = 0;

        for (int j = 0; j < 4; ++j)
        {
            if (arr[j])
            {
                front++;
            } else {
                back++;
            }
        }

        if (back == 1 && front == 3) cout << 'A' << '\n';
        else if (back == 2 && front == 2) cout << 'B' << '\n';
        else if (back == 3 && front == 1) cout << 'C' << '\n';
        else if (back == 4 && front == 0) cout << 'D' << '\n';
        else cout << 'E' << '\n';
    }
    return 0;
}