import Foundation

// 1차
func solution(_ numbers:[Int]) -> String {  
    return numbers.map{ String($0) }.sorted(by: >).joined()
}

// 2차
func solution(_ numbers:[Int]) -> String {
    // custom 정렬
    func cmp(_ s1:String, _ s2:String) -> Bool {
        return "\(s1)"+"\(s2)" > "\(s2)"+"\(s1)"
    }

    return numbers.map{ String($0) }.sorted(by: cmp).joined()
}