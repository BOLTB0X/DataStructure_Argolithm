# 2018 KAKAO BLIND RECRUITMENT [1차] 캐시
def solution(cacheSize, cities):
    answer = 0
    cache = []

    for city in cities:
        city = city.lower()
        if cacheSize == 0:
            answer += 5
        else:
            if not city in cache:
                if len(cache) == cacheSize:
                    cache.pop(0)
                cache.append(city)
                answer += 5
            else:
                cache.pop(cache.index(city))
                cache.append(city)
                answer += 1
    return answer
