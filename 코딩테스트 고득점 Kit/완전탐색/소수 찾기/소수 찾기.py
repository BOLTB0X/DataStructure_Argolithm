from itertools import permutations
import math


def is_prime(p):
    if p == 0 or p == 1:
        return False

    for i in range(2, int(math.sqrt(p)) + 1):
        if p % i == 0:
            return False
    return True


def solution(numbers):
    answer = 0
    candi = []

    for i in range(1, len(numbers) + 1):
        per_str = set(permutations(numbers, i))
        for per in per_str:
            tmp = ""
            for pe in per:
                tmp += pe
            candi.append(int(tmp))

    print(candi)
    for ca in set(candi):
        if is_prime(ca):
            answer += 1
    return answer
