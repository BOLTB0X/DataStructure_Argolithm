def solution(word):
    answer = 0
    moum = "AEIOU"
    resArr = []

    def DFS(arr, newMoum, depth, lim):
        nonlocal resArr
        if depth == lim:
            if not newMoum in resArr:
                resArr.append(newMoum)
            return

        for a in arr:
            DFS(arr, newMoum+a, depth+1, lim)

    for i in range(1, 6):
        DFS(moum, "", 0, i)

    resArr.sort()
    # print(resArr)
    for i in range(len(resArr)):
        if word == resArr[i]:
            answer = i+1
            break
    return answer
