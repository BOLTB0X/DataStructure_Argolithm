// https://school.programmers.co.kr/learn/courses/30/lessons/12899

func solution(_ n: Int) -> String {
    var answer:String = ""
    var tmpArr:[String] = []
    var number = n

    while n > 0 {
        if n % 3 == 1 {
            tmpArr.append(String(n%3))
            n /= 3
        } else {
            tmpArr.append("4")
            n /= 3
            n -= 1
        }
    }

    answer = tmpArr.reversed().joined()
    return answer
}