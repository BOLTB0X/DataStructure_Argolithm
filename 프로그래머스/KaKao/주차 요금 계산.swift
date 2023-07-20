import Foundation

func solution(_ fees:[Int], _ records:[String]) -> [Int] {
    var answer:[Int] = []
    // fees: 기본 시간(분), 기본 요금(원), 단위 시간(분), 단위 요금(원)
    var inInfo: [String: Int] = [:]
    var carInfo: [String: Int] = [:]
    
    for record in records {
        // splitedR: 시간, 차량번호, 상태
        let splitedR = record.components(separatedBy: " ")
        
        if splitedR[2] == "IN" {
            inInfo[splitedR[1]] = getTotalMinu(splitedR[0])
        } else { // 나가는 경우
            if let time = carInfo[splitedR[1]] { // 있는 경우
                carInfo[splitedR[1]]! += (getTotalMinu(splitedR[0]) - inInfo[splitedR[1]]!)
            } else { // 새로 넣는 경우
                carInfo[splitedR[1]] = (getTotalMinu(splitedR[0]) - inInfo[splitedR[1]]!)
            }
            inInfo.removeValue(forKey: splitedR[1])
        }
    }
    
    // 남아 있는 차가 있다면
    var restCarNum: [String] = []
    var restTime: [Int] = []
    for (carNum, time) in inInfo {
        restCarNum.append(carNum)
        restTime.append(time)
    }
    
    while restCarNum.count > 0 {
        let num = restCarNum.removeFirst()
        let t = restTime.removeFirst()
        
        if let time = carInfo[num] { // 있는 경우
            carInfo[num]! += (getTotalMinu("23:59") - t)
        } else { // 새로 넣는 경우
            carInfo[num] = (getTotalMinu("23:59") - t)
        }
    }
    
    //print(carInfo)
    var tmpAnswer:[[Int]] = []
    for (num, time) in carInfo {
        tmpAnswer.append([Int(num)! ,getTotalFee(baseH: fees[0], baseFee: fees[1], unitH: fees[2], unitFee: fees[3], time: time)])
    }
    answer = tmpAnswer.sorted{$0[0] < $1[0]}.map{$0[1]}
    //print(tmpAnswer)
    return answer
}

func getTotalMinu(_ time: String) -> Int {
    let t = time.components(separatedBy: ":")
    return (Int(t[0])! * 60) + Int(t[1])!
}

// 기본 시간(분), 기본 요금(원), 단위 시간(분), 단위 요금(원)
func getTotalFee(baseH: Int, baseFee: Int, unitH: Int, unitFee: Int, time: Int) -> Int {
    if baseH >= time {
        return baseFee
    } 
    
    let tmp = ceil(Float(time - baseH)/Float(unitH))
    //print(time, tmp)
    return baseFee + unitFee*Int(tmp)
}