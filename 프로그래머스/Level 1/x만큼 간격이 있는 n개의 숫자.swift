func solution(_ x:Int, _ n:Int) -> [Int64] {
    // 단순풀이
    var answer:[Int64] = []
    var x:Int64 = Int64(x)
    var number:Int64 = x
    
    for i in 0..<n {
        answer.append(number)
        number += x
    }
    
    return answer
}