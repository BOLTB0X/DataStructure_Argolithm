// https://school.programmers.co.kr/learn/courses/30/lessons/12985
import Foundation

func solution(_ n:Int, _ a:Int, _ b:Int) -> Int
{
    var answer = 0
    var a = a
    var b = b

    // 1 2, 3 4, 5 6, 7 8
    while a != b {
        a = (a/2) + (a%2)
        b = (b/2) + (b%2)
        answer += 1
    }

    return answer
}