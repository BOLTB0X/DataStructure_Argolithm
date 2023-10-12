// 2023 KAKAO BLIND RECRUITMENT 표 병합
import Foundation

func solution(_ commands:[String]) -> [String] {
    var answer:[String] = []
    var table:[[String]] = Array(repeating: Array(repeating: "EMPTY", count: 50), count: 50)
    var merged:[[(Int,Int)]] = []
    
    for i in 0..<50 {
        var line: [(Int, Int)] = []
        for j in 0..<50 {
            line.append((i, j))
        }
        merged.append(line)
    }
    
    for cmd in commands {
        let splitedCmd = cmd.components(separatedBy: " ")
        //print(splitedCmd)
        
        if splitedCmd[0] == "UPDATE" {
            if splitedCmd.count == 4 {
                let m = merged[Int(splitedCmd[1])!-1][Int(splitedCmd[2])!-1]
                table[m.0][m.1] = splitedCmd[3]
            } else {
                for i in 0..<50 {
                    for j in 0..<50 {
                        if table[i][j] == splitedCmd[1] {
                            table[i][j] = splitedCmd[2]
                        }
                    }
                }
            }
        } else if splitedCmd[0] == "MERGE" {
            let n1 = merged[Int(splitedCmd[1])!-1][Int(splitedCmd[2])!-1]
            let n2 = merged[Int(splitedCmd[3])!-1][Int(splitedCmd[4])!-1]
            
            if n1 == n2 {
                continue
            }
            
            if table[n1.0][n1.1] == "EMPTY" {
                table[n1.0][n1.1] = table[n2.0][n2.1]
            }
            
            for i in 0..<50 {
                for j in 0..<50 {
                    if merged[i][j] == n2 {
                        merged[i][j] = n1
                    }
                }
            }
            
        } else if splitedCmd[0] == "UNMERGE" {
            let m = merged[Int(splitedCmd[1])!-1][Int(splitedCmd[2])!-1]
            let preVal = table[m.0][m.1]
            
            for i in 0..<50 {
                for j in 0..<50 {
                    if merged[i][j] == m {
                        merged[i][j] = (i, j)
                        table[i][j] = "EMPTY"
                    }
                }
            }
            table[Int(splitedCmd[1])!-1][Int(splitedCmd[2])!-1] = preVal
            
        } else if splitedCmd[0] == "PRINT" {
            let m = merged[Int(splitedCmd[1])!-1][Int(splitedCmd[2])!-1]
            answer.append(table[m.0][m.1])
        }
    }
    
    return answer
}