//
//  main.swift
//  17266 어두운 굴다리
//  https://www.acmicpc.net/problem/17266
//  Created by KyungHeon Lee on 2023/09/11.
//

import Foundation

let N = Int(readLine()!)!
let M = Int(readLine()!)!
let rows: [Int] = readLine()!.split(separator: " ").map { Int(String($0))!}
var answer = Int.max

func binarySearch() {
    var l: Int = 0
    var r: Int = N
    var mid: Int = 0
    
    while l <= r {
        mid = (l+r)/2
        if check(mid) {
            answer = min(answer, mid)
            r = mid-1
        } else {
            l = mid+1
        }
    }
    
    func check(_ x: Int) -> Bool {
        var cnt: Int = 0
        
        for r in rows {
            if r - x <= cnt {
                cnt = r + x
            } else {
                return false
            }
        }
        
        return cnt >= N ? true : false
    }
    
    return
}


// 0 1 (2) 3 (4) 5

var arr = Array(0...N)
binarySearch()
print(answer)
