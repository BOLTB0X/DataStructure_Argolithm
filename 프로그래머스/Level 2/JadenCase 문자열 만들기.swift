func solution(_ s:String) -> String {
    var answer:[String] = []
    var s = s.components(separatedBy: " ")
    
    for i in 0..<s.count {   
        var idx = 0
        var tmp = ""
        for ch in s[i] {
            if idx == 0 {
                tmp += ch.uppercased()
            } else {
                tmp += ch.lowercased()
            }
            idx += 1
        }
        answer.append(tmp)
    }
    
    return answer.joined(separator: " ")
}