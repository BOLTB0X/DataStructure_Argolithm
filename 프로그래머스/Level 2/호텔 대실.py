# https://school.programmers.co.kr/learn/courses/30/lessons/155651
def transMinute(strTime):
    h,m = strTime.split(":")
    return int(h)*60+int(m)

def solution(book_time):
    answer = 0
    bookTime = []
    roomArr = []
    
    # 편의로 분단위로 바꿔줌
    for book in book_time:
        bookTime.append([transMinute(book[0]), transMinute(book[1]) + 10]) # 청소시간도 같이
    
    bookTime.sort() # 시작 시간이 빠른 순으로
    #print(bookTime)
    
    for book in bookTime:
        if not roomArr:
            roomArr.append(book)
            continue
        
        # roomArr에 넣을 수 있는지 체크
        for i in range(len(roomArr)):
            # 이번 예약시간이 현재 룸의 끝나는 시간과 같다면
            if book[0] >= roomArr[i][1]:
                roomArr[i][0] = book[0] # 교체
                roomArr[i][1] = book[1]
                break
        else:
            roomArr.append(book)
    #print(roomArr)
    answer = len(roomArr)
    return answer