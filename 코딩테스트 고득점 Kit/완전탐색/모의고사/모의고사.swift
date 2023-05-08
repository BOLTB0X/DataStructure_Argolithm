import Foundation

func solution(_ answers:[Int]) -> [Int] {
    var answer:[Int] = []
    let supoja1:[Int] = [1,2,3,4,5] // 길이 5
    let supoja2:[Int] = [2,1,2,3,2,4,2,5] // 길이 8
    let supoja3:[Int] = [3,3,1,1,2,2,4,4,5,5] // 길이 10
    
    var totalAns:[Int] = [0,0,0] // 합
    
    for i in answers.enumerated() {
        // 현재 답이 수포자1과 같다면
        if i.1 == supoja1[i.0 % supoja1.count] {
            totalAns[0] += 1
        }
        // 현재 답이 수포자2과 같다면
        if i.1 == supoja2[i.0 % supoja2.count] {
            totalAns[1] += 1
        }
        // 현재 답이 수포자1과 같다면
        if i.1 == supoja3[i.0 % supoja3.count] {
            totalAns[2] += 1
        }
    }
    
    // 마지막으로 최고점 수포자 찾기
    for i in 0..<3 {
        if totalAns[i] == totalAns.max() { // 배열중 최댓값과 같다면
            answer.append(i + 1)
        }
    }
    return answer
}