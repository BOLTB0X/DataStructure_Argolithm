// 최대공약수
func gcd(_ a: Int, _ b:Int) -> Int {
    if b == 0 {
        return a
    }
    return gcd(b, a%b)
}

// 최소공배수
func lcm(_ a:Int, _ b:Int) -> Int {
    return a * b / gcd(a, b)
}

func solution(_ n:Int, _ m:Int) -> [Int] {
    // 단순풀이
    return [gcd(n,m), lcm(n,m)]
}