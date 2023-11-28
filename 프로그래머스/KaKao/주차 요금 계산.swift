// 2022 KAKAO BLIND RECRUITMENT 주차 요금 계산
// https://school.programmers.co.kr/learn/courses/30/lessons/92341
import Foundation

func solution(_ fees:[Int], _ records:[String]) -> [Int] {
    var answer: [Int] = []
    var inParkingState: [String:Int] = [:]
    var outParkingState: [String:Int] = [:]
    
    for record in records {
        let splitedRecord = record.components(separatedBy: " ")
        
        if splitedRecord[2] == "IN" {
            inParkingState[splitedRecord[1]] = translateIntegerTime(splitedRecord[0])
        } else {
            let inTime = inParkingState[splitedRecord[1]]!
            let outTime = translateIntegerTime(splitedRecord[0])
            outParkingState[splitedRecord[1], default: 0] += (outTime - inTime)
            inParkingState[splitedRecord[1]] = nil
        }
    }

    for (key, value) in inParkingState {
        let outTime = translateIntegerTime("23:59")
        outParkingState[key, default: 0] += (outTime - value)
    }
    
    let sortedCarNumber = outParkingState.sorted { $0.key < $1.key }
    for carNumber in sortedCarNumber {
        answer.append(chargeFee(fees[0], fees[1], fees[2], fees[3], carNumber.value))
    }

    return answer
}

func translateIntegerTime(_ time : String) -> Int {
    let splitedTime = time.components(separatedBy: ":")
    return Int(splitedTime[0])! * 60 + Int(splitedTime[1])!
}

func chargeFee(_ basicTime: Int, _ basicFee: Int, _ unitTime: Int, _ unitFee: Int, _ usedTime: Int) -> Int {
    if usedTime <= basicTime {
        return basicFee
    }
    
    let temp = ceil(Double(usedTime-basicTime) / Double(unitTime))
    return basicFee + Int(temp) * unitFee
}