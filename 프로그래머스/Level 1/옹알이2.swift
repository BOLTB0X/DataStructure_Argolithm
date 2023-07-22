import Foundation

func solution(_ babbling:[String]) -> Int {
    var answer:Int = 0
    var words:[String] = ["aya", "ye", "woo", "ma"]
    
    for babb in babbling {
        var b = babb
        for word in words {
            let tmp = word + word
            if !b.contains(tmp) {
                b = b.replacingOccurrences(of: word, with: " ")
            }
        }
        print(b)
        if b.isAllSpace() {
            answer += 1
        }
    }
    return answer
}

extension String {
    func isAllSpace() -> Bool {
        return allSatisfy { $0.isWhitespace}
    }
}