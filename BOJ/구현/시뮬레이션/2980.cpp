// 2980 도로와 신호등
// https://www.acmicpc.net/problem/2980
#include <iostream>
#include <vector>

using namespace std;

struct info {
    int D, R, G;
};

struct cell {
    int val, redTime, greenTime;
};

void update(int N, int L, cell* dist, vector<info> lights) {
    for (auto& light: lights)
    {
        if (dist[light.D].greenTime > 0)
        {
            dist[light.D].greenTime--;
            if (dist[light.D].greenTime == 0) 
            {
                dist[light.D].redTime = light.R;
            }
        }

        else if (dist[light.D].redTime > 0)
        {
            dist[light.D].redTime--;
            if (dist[light.D].redTime == 0) 
            {
                dist[light.D].greenTime = light.G;
            }
        }
    }
    return;
}

int solution(int N, int L, vector<info> lights) {
    int answer = 0;

    // D는 신호등의 위치이며, R과 G는 빨간색, 초록색이 지속되는 시간
    cell dist[1001];

    for (int i = 0; i <= L; ++i)
    {
        dist[i].val = 1;
        dist[i].greenTime = 0;
        dist[i].redTime = 0;
    }

    for (auto &light: lights)
    {
        dist[light.D].val = -1;
        dist[light.D].redTime = light.R;
        dist[light.D].greenTime = 0;
    }

    int cur = 0;
    while (cur < L)
    {
        // 상근이의 트럭이 도로에 진입했을 때, 모든 신호등의 색상은 빨간색이고, 사이클이 막 시작한 상태
        update(N, L, dist, lights);
        //cout << cur << '\n';
        // 진행
        if (dist[cur+1].val == 1 || (dist[cur+1].val == -1 && dist[cur+1].greenTime > 0)) cur++;
        // update
        answer++;
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, L;
    vector<info> lights;

    cin >> N >> L;
    lights = vector<info> (N);

    for (int i = 0; i < N; ++i)
    {
        cin >> lights[i].D >> lights[i].R >> lights[i].G;
    }

    cout << solution(N, L, lights);

    return 0;
}