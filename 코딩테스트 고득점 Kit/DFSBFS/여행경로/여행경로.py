def solution(tickets):
    answer = []
    visited = [False] * len(tickets)
    tickets.sort()

    def DFS(visited, cur, path):
        nonlocal answer
        if answer:
            return

        if not answer and len(path) == len(tickets)+1:
            answer.extend(path)
            return

        for i in range(len(tickets)):
            start = tickets[i][0]
            end = tickets[i][1]

            if not visited[i] and cur == start:
                visited[i] = True
                path.append(end)

                DFS(visited, end, path)

                path.pop()
                visited[i] = False
        return

    DFS(visited, "ICN", ["ICN"])
    return answer
