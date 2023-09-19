#include <string>
#include <vector>

using namespace std;

int queen[13];
int cnt = 0;

int abs(int a) {
    return a < 0 ? -a : a;
}

bool check(int n, int x, int y) {
    for (int i = 0; i < x; ++i) {
        if (queen[i] == y || abs(y-queen[i]) == x-i) {
            return false;
        }
    }
    return true;
}

void DFS(int n, int x) {
    if (x == n) {
        cnt++;
        return;
    }
    
    for (int y = 0; y<n; ++y) {
        if (check(n, x, y)) {
            queen[x] = y;
            DFS(n, x+1);
        }
    }
    return;
}

int solution(int n) {
    int answer = 0;
    DFS(n, 0);
    answer = cnt;
    return answer;
}