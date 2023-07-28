import Foundation

func solution(_ number:String, _ k:Int) -> String {
    var answer:String = ""
    var number = number.map { String($0) }
    var k = k
    var stack:[String] = []
    
    for n in number {
        while !stack.isEmpty && stack.last! < n && k > 0 {
            stack.removeLast()
            k -= 1
        }
        stack.append(n)
    }
    
    // 다 안지워질수도 있으므로
    if k > 0 {
        stack = Array(stack[0..<stack.count-k])
    }
    
    answer = stack.joined()
    return answer
}