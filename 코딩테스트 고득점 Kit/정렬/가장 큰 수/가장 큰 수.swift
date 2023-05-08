import Foundation

func solution(_ numbers:[Int]) -> String {
    var answer: String = ""
    var flag: Bool = false // 체크용
    
    // custom 정렬
    func cmp(_ s1:String, _ s2:String) -> Bool {
        return "\(s1)"+"\(s2)" > "\(s2)"+"\(s1)"
    }
    
    var numbers = numbers.map{ String($0) }.sorted(by: cmp)
    
    for i in 0..<numbers.count {
        if numbers[i] != "0" && flag == false {
            flag = true
            answer = ""
        }
        
        if flag {
            answer += numbers[i]
        } else { // 000000 맞닥드린 것
            answer = "0"
        }
    }
    return answer
}