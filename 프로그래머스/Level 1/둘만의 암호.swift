// https://school.programmers.co.kr/learn/courses/30/lessons/155652
import Foundation

func solution(_ s:String, _ skip:String, _ index:Int) -> String {
    var answer: String = ""
    var s = s.map { String($0) }
    var skip = skip.map { String($0) }
    var alp = "abcdefghijklmnopqrstuvwxyz".map { String($0) }
    
    for i in 0..<s.count {
        var idx = alp.firstIndex(of: s[i])!
        var cnt = 0
        
        while cnt < index {
            idx += 1
            if idx >= 26 {
                idx = 0;
            }
            
            if skip.contains(alp[idx]) {
                continue
            }
            
            cnt += 1
        }
        
        answer += alp[idx]
    }
    return answer
}