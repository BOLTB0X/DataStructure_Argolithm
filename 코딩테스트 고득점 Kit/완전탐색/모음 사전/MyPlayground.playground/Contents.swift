import UIKit

func solution(_ word:String) -> Int {
    var answer:Int = 0
    
    let moum:[String] = ["A","E","I","O","U"]
    var words = Set<String>()
    
    for i in 1...5 {
        DFS("", 0, i)
        print(words)
    }
    
    let wordsArr = words.map{String($0)}.sorted(by: <)
    print(wordsArr)
    answer = wordsArr.firstIndex(of: word)!+1 // 옵셔널 조심
    return answer
    
    func DFS(_ cur:String, _ level:Int, _ size: Int) {
        if level == size {
            words.insert(cur)
            return
        }
        
        for i in 0..<5 {
            var next = cur
            next += moum[i]
            DFS(next, level+1, size)
        }
        return
    }
}

let word1 = "AAAAE"
let word2 = "AAAE"
let word3 = "I"
let word4 = "EIO"

print(solution(word1))
//print(solution(word2))
//print(solution(word3))
//print(solution(word4))

