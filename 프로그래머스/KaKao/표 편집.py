# 2021 카카오 채용연계형 인턴십 표 편집
def solution(n, k, cmd):
    answer = ["O"]*n
    table = {i: [i-1, i+1] for i in range(n)}
    table[0] = [None, 1]
    table[n-1] = [n-2, None]
    stack = []
    # print(table)

    for c in cmd:
        if len(c) > 1:
            c1, c2 = c.split(" ")

            if c1 == "U":
                for _ in range(int(c2)):
                    k = table[k][0]

            elif c1 == "D":
                for _ in range(int(c2)):
                    k = table[k][1]

        else:
            if c == "C":  # 삭제
                answer[k] = "X"
                pre, next = table[k]

                stack.append([pre, k, next])

                if next == None:
                    k = table[k][0]
                else:
                    k = table[k][1]

                if pre == None:
                    table[next][0] = None
                elif next == None:
                    table[pre][1] = None
                else:
                    table[pre][1] = next
                    table[next][0] = pre

            elif c == "Z":
                pre, cur, next = stack.pop()
                answer[cur] = "O"

                if pre == None:
                    table[next][0] = cur
                elif next == None:
                    table[pre][1] = cur
                else:
                    table[next][0] = cur
                    table[pre][1] = cur

    return "".join(answer)
