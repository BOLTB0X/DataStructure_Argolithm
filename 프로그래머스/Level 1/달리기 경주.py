# https://school.programmers.co.kr/learn/courses/30/lessons/178871
def solution(players, callings):
    players_dic = {val: idx for idx, val in enumerate(players)}

    for call in callings:
        cur = players_dic[call]
        curPlayer = call  # 호명 받은 선수
        front = cur-1
        frontPlayer = players[front]  # 호명 받은 선수 앞 선수

        players_dic[curPlayer] = front
        players_dic[frontPlayer] = cur

        players[cur], players[front] = players[front], players[cur]

    answer = sorted(players_dic, key=lambda k: players_dic[k])
    return answer
