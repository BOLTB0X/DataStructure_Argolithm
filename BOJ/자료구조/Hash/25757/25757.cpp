// 25757 임스와 함께하는 미니게임
#include <iostream>
#include <map>

using namespace std;

int N;
char G;

int main(void) {
    map<string,int> m;

    cin >> N >> G;

    for (int i = 0; i < N; ++i) {
        string input;
        cin >> input;
        m[input] = 1;
    }

    if (G == 'Y') cout << m.size();
    else if (G == 'F') cout << m.size() / 2;
    else cout << m.size() / 3;

    return 0;
}