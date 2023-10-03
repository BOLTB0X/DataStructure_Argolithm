// 2529 부등호
// https://www.acmicpc.net/problem/2529
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string res1 = "-9876543210", res2 = "9876543210";
int K;
vector<char> v;
vector<int> visited(10, 0);

void DFS(string currentNumber, int depth) {
    if (depth == K+1)
    {

        if (stoll(res1) < stoll(currentNumber)) res1 = currentNumber;
        if (stoll(res2) > stoll(currentNumber)) res2 = currentNumber;

        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (visited[i]) continue;

        if (depth > 0) 
        {
            if (v[depth-1] == '>' && currentNumber[depth-1] - '0' > i)
            {
                visited[i] = 1;
                DFS(currentNumber+to_string(i), depth+1);
                visited[i] = 0;
            }

            if (v[depth-1] == '<' && currentNumber[depth-1] - '0' < i)
            {
                visited[i] = 1;
                DFS(currentNumber+to_string(i), depth+1);
                visited[i] = 0;
            }
        } else
        {
            visited[i] = 1;
            DFS(currentNumber+to_string(i), depth+1);
            visited[i] = 0;
        }
    }

    return;
}

void solution(void) {

    DFS("" ,0);

    cout << res1 << '\n' << res2 << '\n';
    return;
}

int main(void) {
    cin >> K;
    v = vector<char>(K);

    for (int i = 0; i < K; ++i) 
    {
        cin >> v[i];
    }

    solution();
    return 0;
}