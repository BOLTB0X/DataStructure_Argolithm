from itertools import permutations


def solution(k, dungeons):
    answer = -1

    for per in permutations(dungeons, len(dungeons)):
        cur = k
        cnt = 0
        for p in per:
            if p[0] <= cur:
                cnt += 1
                cur -= p[1]

        answer = max(answer, cnt)
    return answer
