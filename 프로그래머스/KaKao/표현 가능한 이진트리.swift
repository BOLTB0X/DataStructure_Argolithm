// 2023 KAKAO BLIND RECRUITMENT 표현 가능한 이진트리
// https://school.programmers.co.kr/learn/courses/30/lessons/150367
import Foundation

func convertFullBinaryTree(_ number: String) -> [Character] {
    var level: Double = 0
    var nodeCount: Int = 1
    
    while nodeCount < number.count {
        level += 1
        nodeCount += Int(pow(2, level))
    }
    
    return Array(repeating: "0", count: nodeCount - number.count) + number.map { $0 }
}

func isBinaryTree(_ bt: [Character]) -> Bool {
    func isHaveZero(_ subTree: [Character]) -> Bool {
        for sub in subTree {
            if sub != "0" { return false }
        }
        return true
    }
    
    if bt.count == 1 {
        return true
    }
    
    let leftNode = Array(bt[0..<bt.count / 2])
    let midNode = bt[bt.count / 2]
    let rightNode = Array(bt[(bt.count / 2 + 1)...])
    
    if midNode == "0" {
        return isHaveZero(leftNode) && isHaveZero(rightNode)
    }
    
    return isBinaryTree(leftNode) && isBinaryTree(rightNode)
}

func solution(_ numbers:[Int64]) -> [Int] {
    var answer: [Int] = []
    
    // 주어진 수를 이진수로 변환
    // 부족한 부분을 0으로 채워서 포화 이진 트리 생성
    // 중위 순회를 통해 노드를 순차적으로 확인하면서 이진 트리로 표현 가능한지 체크
    for number in numbers {
        let binaryNumber = String(number, radix: 2)
        let fullBinaryTree = convertFullBinaryTree(binaryNumber)
        //print(binaryNumber, fullBinaryTree)
        let flag = isBinaryTree(fullBinaryTree)
        answer.append(flag ? 1 : 0)
    }
    return answer
}