// 2020 KAKAO BLIND RECRUITMENT 문자열 압축
// https://school.programmers.co.kr/learn/courses/30/lessons/60057
import Foundation

func solution(_ s:String) -> Int {
    var answer: Int = s.count
    let s = s.map{ String($0) }
    
    for i in 1..<(s.count/2)+1 {
        let compressionString = compressString(s, i)
        answer = min(answer, compressionString.count)
    }
    return answer
}

func compressString(_ s: [String], _ len: Int) -> String {
    var ret: String = ""
    var parsing = s[0..<len].joined()
    var cnt = 1;
        
    for i in stride(from: len, to: s.count, by: len) {
        var tempParsing: String {
            if i+len <= s.count {
                return s[i..<i+len].joined()
            } else {
                return s[i..<s.count].joined()
            }
        }
            
        if parsing == tempParsing {
            cnt += 1
        } else {
            if cnt > 1 {
                parsing = String(cnt) + parsing
            } 
    
            ret += parsing
            cnt = 1
            parsing = tempParsing
        }
    }
        
    if cnt > 1 {
        parsing = (String(cnt) + parsing)
    } 
    ret += parsing
    
    return ret
}