// https://school.programmers.co.kr/learn/courses/30/lessons/81303
import Foundation

var stack: [Int] = []
var table: [(Int, Int)] = []
var inTable: [Bool] = []
var cur: Int = 0

func updateTypeU(_ val: Int) {
    for _ in 0..<val {
        if table[cur].0 != -1 { 
            cur = table[cur].0
        }
    }
    return
}

func updateTypeD(_ val: Int) {
    for _ in 0..<val {
        if table[cur].1 != -1 { 
            cur = table[cur].1
        }
    }
    return
}

func updateTypeC(_ n: Int) {
    let prev = table[cur].0
    let next = table[cur].1
    inTable[cur] = false
    stack.append(cur)
    
    if prev != -1 { table[prev].1 = next } 
    
    if next != -1 { table[next].0 = prev }
    
    cur = table[cur].1 == -1 ? table[cur].0 : table[cur].1
    return
}

func updateTypeZ() {
    guard let top = stack.last else { return }
    stack.removeLast()
    inTable[top] = true
    
    let prev = table[top].0
    let next = table[top].1
    
    if prev != -1 {
        table[prev].1 = top
    }
    
    if next != -1 {
        table[next].0 = top
    }
}

func solution(_ n:Int, _ k:Int, _ cmd:[String]) -> String {
    var answer = ""
    cur = k
    inTable = Array(repeating: true, count: n)
    
    for i in 0..<n {
        if i == n-1 {
            table.append((i - 1, -1))
        } else {
            table.append((i - 1, i + 1))
        }
    }
    
    for c in cmd {
        let splitedCmd = c.split(separator: " ").map { String($0)}
        switch splitedCmd[0] {
            case "U":
                updateTypeU(Int(splitedCmd[1])!)
            case "D":
                updateTypeD(Int(splitedCmd[1])!)
            case "C":
                updateTypeC(n)
            case "Z":
                updateTypeZ()
            default:
                break
        }
    }
    
    for i in inTable {
        answer += i ? "O" : "X"
    }
    
    return answer
}