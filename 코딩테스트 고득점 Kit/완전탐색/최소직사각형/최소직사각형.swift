import Foundation

func solution(_ sizes:[[Int]]) -> Int {
    var w:Int = 0 // 가로
    var h:Int = 0 // 세로

    for size in sizes {
        // 가로는 최댓값중 최대
        // 세로는 최솟값중 최대
        w = max(w, size.max()!) 
        h = max(h, size.min()!)

    }
    return w * h
}

---
// 너무 원초적인 풀이
import Foundation

func Max(_ a:Int, _ b:Int) -> Int {
    return a > b ? a : b
}

func Min(_ a:Int, _ b:Int) -> Int {
    return a < b ? a : b
}

func solution(_ sizes:[[Int]]) -> Int {
    var w: Int = -1
    var h: Int = -1
    
    for i in 0..<sizes.count {
        w = Max(Max(sizes[i][0], sizes[i][1]), w)
        h = Max(Min(sizes[i][0], sizes[i][1]), h)
        print("\(i) \(w) \(h)")
    }
    
    return w*h
}