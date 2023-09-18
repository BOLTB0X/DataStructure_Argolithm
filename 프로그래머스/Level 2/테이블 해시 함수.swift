// https://school.programmers.co.kr/learn/courses/30/lessons/147354
import Foundation

func solution(_ data:[[Int]], _ col:Int, _ row_begin:Int, _ row_end:Int) -> Int {
    var answer: Int = 0
    var S:[Int] = []
    
    let sortedData = data.sorted { (a, b) in // 2
        if a[col-1] == b[col-1] {
            return a[0] > b[0]
        }
        return a[col-1] < b[col-1]
    }
    //print(sortedData)
    
    for i in row_begin-1..<row_end {
        var tot: Int = 0
        for j in 0..<sortedData[i].count {
            //print(sortedData[i][j])
            tot += (sortedData[i][j]%(i+1))
        }
        S.append(tot)
    }
    
    for s in S {
        answer = Int(s^answer)
    }
    return answer
}