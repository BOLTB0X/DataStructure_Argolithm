// https://school.programmers.co.kr/learn/courses/30/lessons/81303
import Foundation

var stack: [Int] = []

func updateTypeU(_ X:Int, _ table: [(prev: Int, next: Int)], _ k: inout Int) {
    for _ in 0..<X {
        if k == 0 { return }
        k = table[k].prev
    }
}

func updateTypeD(_ X:Int, _ n: Int, _ table: [(prev: Int, next: Int)], _ k: inout Int) {
    for _ in 0..<X {
        if k == n-1 { return }
        k = table[k].next
    }
}

func updateTypeC(_ n:Int, table: inout [(prev: Int, next: Int)], inTable: inout [Bool], _ k: inout Int) {
    let removedPrev = table[k].prev
    let romovedNext = table[k].next
    stack.append(k)
    inTable[k] = false
    
    if removedPrev != -1 {
        table[removedPrev].next = romovedNext
    }
    
    if romovedNext != -1 {
        table[romovedNext].prev = removedPrev
    }
    
    k = romovedNext == -1 ? removedPrev : romovedNext
}

func updateTypeZ(_ n:Int, table: inout [(prev: Int, next: Int)], inTable: inout [Bool], _ k: inout Int) {
    if stack.isEmpty { return }
    
    let top = stack.removeLast()
    inTable[top] = true
    
    let restoredPrev = table[top].prev
    let restoredNext = table[top].next
    
    if restoredPrev != -1 {
        table[restoredPrev].next = top
    }
    
    if restoredNext != -1 {
        table[restoredNext].prev = top
    }
} 

func solution(_ n:Int, _ k:Int, _ cmd:[String]) -> String {
    var answer: String = ""
    var table: [(prev: Int, next: Int)] = []
    var k = k
    var inTable: [Bool] = Array(repeating: true, count: n)
    
    for i in 0..<n {
        if i == n-1 {
            table.append((i-1, -1))
        } else {
            table.append((i-1, i+1))
        }
    }
    
    
    for c in cmd {
        let splitedC = c.split(separator: " ")
        switch splitedC[0] {
            case "U":
            updateTypeU(Int(splitedC[1])!, table, &k)
            break
            case "D":
            updateTypeD(Int(splitedC[1])!, n, table, &k)
            break
            case "C":
            updateTypeC(n, table: &table, inTable: &inTable, &k)
            break
            default:
            updateTypeZ(n, table: &table, inTable: &inTable, &k)
            break
        }
    }
    
    for t in inTable {
        answer += t ? "O" : "X"
    }
    return answer
}