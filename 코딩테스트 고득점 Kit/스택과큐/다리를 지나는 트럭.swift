import Foundation

func solution(_ bridge_length:Int, _ weight:Int, _ truck_weights:[Int]) -> Int {
    var answer:Int = 0 // 경과시간
    var que = Array(repeating: 0, count: bridge_length)
    var curIndex: Int = 0
    var totalWeight: Int = 0 // 다리의 무게
    
    while curIndex < truck_weights.count {
        // 시간 경과처리
        answer += 1
        totalWeight -= que.removeFirst()
        
        // 다리에 트럭을 더 올릴 수 있는 경우
        if totalWeight+truck_weights[curIndex] <= weight {
            totalWeight += truck_weights[curIndex]
            que.append(truck_weights[curIndex])
            curIndex += 1 // 트럭이 들어가니 인덱스도 증가시켜줌
            
        } else {
            que.append(0) // 그냥 시간처리 용
        }
    }
    return answer+bridge_length
}