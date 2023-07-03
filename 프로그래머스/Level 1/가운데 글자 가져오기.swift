func solution(_ s:String) -> String {
    if Array(s).count % 2 == 0{ // 짝수인 경우
        return String(Array(s)[s.count/2 - 1...(s.count/2)])
    } else { // 홀수인 경우
        return String(Array(s)[s.count/2])
    }
}