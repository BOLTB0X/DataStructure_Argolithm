def solution(n, computers):
    answer = 0
    visited = [False for _ in range(n)]

    def DFS(cur):
        nonlocal visited
        visited[cur] = True

        for i in range(n):
            if not visited[i] and computers[cur][i]:
                DFS(i)

    for i in range(n):
        if not visited[i]:
            DFS(i)
            answer += 1

    return answer
