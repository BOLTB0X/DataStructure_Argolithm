# 2022 카카오블라인드 모집 주차 요금 계산
import math

def transMinute(record):
    tmp = record.split(":")
    return (int(tmp[0])*60) + int(tmp[1])

def getFees(fees, minute):
    if fees[0] >= minute:
        return fees[1]
    return fees[1] + math.ceil((minute - fees[0])/fees[2])*fees[3]

def solution(fees, records):
    answer = []
    carIn = {}
    carOut = {}
    carFees = {}
    
    for record in records:
        carTime, carNum, state = record.split(" ") # 일단 띄어쓰기 기준
        if state == "IN":
            carIn[carNum] = transMinute(carTime)
            
        elif state == "OUT":
            carMinu = transMinute(carTime)
            
            if not carNum in carOut:
                carOut[carNum] = carMinu - carIn[carNum]
            else:
                carOut[carNum] += (carMinu - carIn[carNum]) # 총 이용시간 계산
            carIn.pop(carNum)
    
    # 딕셔너리가 안 비어졌다면
    for (key,value) in carIn.items():
        if key in carOut:
            carOut[key] += (transMinute("23:59")-value)
        else:
            carOut[key] = (transMinute("23:59")-value)
    
    # 요금 계산
    for (key,value) in carOut.items():
        carFees[key] = getFees(fees,value)
    
    #print(carFees)
    answer = [value for (key,value) in sorted(carFees.items(), key = lambda x: x[0])]
    return answer