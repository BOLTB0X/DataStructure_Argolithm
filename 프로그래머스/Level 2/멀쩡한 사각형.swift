// https://school.programmers.co.kr/learn/courses/30/lessons/62048
import Foundation

func solution(_ w:Int, _ h:Int) -> Int64{
    var answer:Int64 = 0
    
    func gcd(_ a: Int, _ b: Int ) -> Int {
        if a%b == 0 {
            return b
        } else if b == 0 {
            return a
        }
        return gcd(b, a%b)
        
    }
    
    answer = Int64(w*h-(w+h-gcd(w,h)))
    return answer
}