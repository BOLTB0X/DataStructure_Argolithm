// 16953 A → B
// https://www.acmicpc.net/problem/16953
#include <iostream>
#include <queue>
#include <cstring>
#define LL long long

using namespace std;

LL mn(LL a, LL b) {
    return  a < b ? a : b;
}

LL Greedy(int A, int B) {
    LL answer = 0;

    while (A < B)
    {
        if (B % 10 == 1)
        {
            B /= 10;
            answer++;
        } else if (B % 2 == 0)
        {
            B /= 2;
            answer++;
        } else 
        {
            B = 0;
            break;
        }
    }
    
    answer = A == B ? answer+1 : -1;

    return answer;
}

LL BFS(int A, int B) {
    LL answer = -1;
    queue<pair<LL,LL>> que;
    que.push({A, 1});

    while (!que.empty())
    {
        auto cur = que.front();
        que.pop();

        if (cur.first == B)
        {
            answer = cur.second;
            break;
        }

        if (cur.first * 2 <= B) 
        {
            que.push({cur.first * 2, cur.second + 1});
        }

        if (cur.first * 10 + 1 <= B)
        {
            que.push({cur.first * 10 + 1, cur.second + 1});
        }
    }
    

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B;
    cin >> A >> B;

    //cout << BFS(A, B);
    cout << Greedy(A, B);
    return 0;
}