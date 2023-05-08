import Foundation

func solution(_ nums:[Int]) -> Int {
    var answer:Int = 0
    let N:Int = nums.count/2 // 길의 반

    // 집합 이용
    var selected:Set<Int> = []

    for n in nums {
        selected.insert(n)
    }

    answer = selected.count <= N ? selected.count : N
    return answer
}