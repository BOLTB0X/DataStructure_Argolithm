import sys
sys.setrecursionlimit(51)


def solution(begin, target, words):
    answer = 51
    visited = [False] * len(words)

    def is_change(word1, word2):
        w = 0
        for i in range(len(word1)):
            if word1[i] != word2[i]:
                w += 1

        return True if w == 1 else False

    def DFS(cur, target, words, visited, depth):
        nonlocal answer

        # 도달 했다면
        if cur == target:
            answer = min(answer, depth)  # 최솟값 반환
            return

        for i in range(len(words)):
            # 변환 가능하고 미방문
            if is_change(cur, words[i]) and not visited[i]:
                visited[i] = True
                DFS(words[i], target, words, visited, depth + 1)
                visited[i] = False
        return

    if target in words:
        # dfs
        DFS(begin, target, words, visited, 0)
    else:
        answer = 0
    return answer
