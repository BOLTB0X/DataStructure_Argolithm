// 2422 한윤정이 이탈리아에 가서 아이스크림을 사먹는데
// https://www.acmicpc.net/problem/2422
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> com;
vector<int> icecream;
vector<int> visited;

bool contains(const vector<int> &v, int target) {
    return find(v.begin(), v.end(), target) != v.end();
}

void combination(vector<int> c, int cur, int depth) {
    if (depth == 3)
    {
        com.push_back(c);
        return;
    }

    for (int i = cur; i < icecream.size(); ++i)
    {
        if (visited[i]) continue;

        visited[i] = true;
        c.push_back(icecream[i]);
        combination(c, i, depth+1);
        c.pop_back();
        visited[i] = false;
    }

    return;
}

int solution(int N, int M, vector<pair<int, int>> benType) {
    int answer = 0;

    // 시간 초과
    // visited = vector<int> (N, 0);
    // for (int i = 1; i <= N; ++i)
    // {
    //     icecream.push_back(i);
    // }

    // combination({}, 0, 0);

    // for (auto c: com)
    // {
    //     int flag = 1;
    //     for (auto b: benType)
    //     {
    //         if (contains(c, b.first) && contains(c, b.second)) 
    //         {
    //             flag = 0;
    //             break;
    //         }
    //     }

    //     if (flag) answer++;
    // }

    vector<vector<int>> ben(N+1, vector<int> (N+1, 0));
    for (auto& c: benType)
    {
        ben[c.first][c.second] = 1;
        ben[c.second][c.first] = 1;
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = i+1; j <= N; ++j)
        {
            if (ben[i][j]) continue;

            for (int k = j+1; k <= N; ++k) 
            {
                if (ben[i][k] || ben[j][k]) continue;
                answer++;
            }
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    vector<pair<int, int>> benType;
    cin >> N >> M;
    benType = vector<pair<int, int>>(M);

    for (int i = 0; i < M; ++i)
    {
        cin >> benType[i].first >> benType[i].second;
    }

    cout << solution(N, M, benType);

    return 0;
}