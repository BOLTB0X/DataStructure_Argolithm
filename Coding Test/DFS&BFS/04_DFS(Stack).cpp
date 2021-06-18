#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool visited[9];
stack<int> st;
vector<int> graph[9];

//DFS 함수 정의
void dfs(int start) {
    //현재 노드를 방문처리
    st.push(start);
    visited[start] = true;
    //현재 노드와 연결된 다른 노드 재귀로 탐색
    while (!st.empty())
    {
        int cur = st.top(); //스택에 가장 상단이 현위치
        st.pop();
        cout << cur << ' ';
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (!visited[next]) {
                st.push(next);
                visited[next] = true;
            }
        }
    }
}

int main(void) {
    // 노드 1에 연결된 노드 정보 저장 
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    // 노드 2에 연결된 노드 정보 저장 
    graph[2].push_back(1);
    graph[2].push_back(7);

    // 노드 3에 연결된 노드 정보 저장 
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    // 노드 4에 연결된 노드 정보 저장 
    graph[4].push_back(3);
    graph[4].push_back(5);

    // 노드 5에 연결된 노드 정보 저장 
    graph[5].push_back(3);
    graph[5].push_back(4);

    // 노드 6에 연결된 노드 정보 저장 
    graph[6].push_back(7);

    // 노드 7에 연결된 노드 정보 저장 
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    // 노드 8에 연결된 노드 정보 저장 
    graph[8].push_back(1);
    graph[8].push_back(7);

    dfs(1);
}