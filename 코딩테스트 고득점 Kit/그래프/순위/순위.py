def solution(n, results):
    answer = 0
    adj = [[0] * (n+1) for _ in range(n+1)]

    for res in results:
        adj[res[0]][res[1]] = 1
        adj[res[1]][res[0]] = -1

    for k in range(1, n+1):
        for a in range(1, n+1):
            for b in range(1, n+1):
                if adj[a][k] == 1 and adj[k][b] == 1:
                    adj[a][b] = 1
                elif adj[a][k] == -1 and adj[k][b] == -1:
                    adj[a][b] = -1

    for i in range(1, n+1):
        if adj[i][1:].count(0) == 1:
            answer += 1

    return answer
