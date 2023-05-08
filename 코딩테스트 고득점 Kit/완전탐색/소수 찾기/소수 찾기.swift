import Foundation

func solution(_ numbers:String) -> Int {
    var answer: Set<Int> = [] // 정답 집합 중복 제거용
    var numbersArr = numbers.map{String($0)} // 편의를 위해

    func isPrime(_ num: String) {
    let num = Int(num)!
    var cnt = 0

    if num > 1{
        for i in 2...num{
            if cnt > 1{
                break
            }
            if num % i == 0 {
                cnt += 1
            }
        }

        if cnt == 1{
            // 3. 소수이면 Set에 추가합니다.
            answer.insert(num) // Set에 넣어주어 중복 제거
        }
    }
}
    
    // DFS로 순열 구현
    func DFS(array: [String], number: String, n: Int, level: Int) {
        // 탈출 조건
        if level == n {
            isPrime(number) // 알아서 중복 제거
            return
        }

        // 배열 순회
        for i in 0..<array.count {
            var new_array = array // var로 교체
            let str = new_array.remove(at: i) // 제거와 제거한 무자
            DFS(array: new_array, number: "\(number)\(String(str))", n: n, level: level + 1)
        }
        
        return
    }
    
    // 1부터 문자열의 길이까지 실행
    for i in 1...numbers.count {
        DFS(array: numbersArr, number: "", n: i, level: 0)
    }
    return answer.count // 길이가 곹 갯수
}