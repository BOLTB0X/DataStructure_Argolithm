# 1515 수 이어 쓰기
# https://www.acmicpc.net/problem/1515
numbers = str(input())
answer = 0

while True:
    answer += 1
    cur = str(answer)

    while len(cur) > 0 and len(numbers) > 0:
        if cur[0] == numbers[0]:
            numbers = numbers[1:]
        cur = cur[1:]

    if numbers == "":
        break
print(answer)
