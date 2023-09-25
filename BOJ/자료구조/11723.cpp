// 11723 집합
// https://www.acmicpc.net/problem/11723
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M, BIT = 0;
    string input;

    cin >> M;

    while (M) {
        int x;
        cin >> input;

        if (input == "add") {
            cin >> x;
            BIT |= (1 << x);
        } else if (input == "remove") {
            cin >> x;
            BIT &= ~(1 << x);
        } else if (input == "check") {
            cin >> x;
            if (BIT & (1 << x)) {
                cout << "1\n";
            } else cout << "0\n";
        } else if (input == "toggle") {
            cin >> x;
            BIT ^= (1 << x);
        } else if (input == "all") {
            BIT = (1 << 21) - 1;
        } else if (input == "empty") {
            BIT = 0;
        }

        M--;
    }
    
    return 0;
}