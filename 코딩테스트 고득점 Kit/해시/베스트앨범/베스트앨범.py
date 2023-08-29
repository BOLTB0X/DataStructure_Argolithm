def solution(genres, plays):
    answer = []
    totalDic = {}
    indexDic = {}

    for i in range(len(genres)):
        if genres[i] in totalDic:
            totalDic[genres[i]] += plays[i]
            indexDic[genres[i]].append(i)
        else:
            totalDic[genres[i]] = plays[i]
            indexDic[genres[i]] = [i]

    sortedGenres = sorted(totalDic.items(), key=lambda x: x[1], reverse=True)
    # print(sortedGenres)

    for genre in sortedGenres:
        sortedArr = sorted(indexDic[genre[0]],
                           key=lambda x: plays[x], reverse=True)
        answer.append(sortedArr[0])
        if len(sortedArr) > 1:
            answer.append(sortedArr[1])
    return answer
