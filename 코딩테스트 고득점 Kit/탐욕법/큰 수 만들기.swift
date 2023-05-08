import Foundation

func solution(_ number:String, _ k:Int) -> String {
    // 스택을 이용
    var stack:[Int] = []
    var number = number.map{ Int(String($0))!} // 편의용
    var cnt:Int = 0 // 지운 횟수
    
    for i in 0..<number.count {
        // 스택에 지울 후보인 숫자들을 넣어 현재 들어가는 수보다 작으면 pop
        while stack.count > 0 && stack.last! < number[i] && cnt < k {
            stack.removeLast() // 스택 상단
            cnt += 1 // 카운트
        }
        stack.append(number[i])
    }
    
    // 만약 하나도 안지워지는 경우
    // 맨 뒤부터 k번 지움
    if cnt == 0 {
        for _ in 1...k {
            stack.removeLast()
        }
    }
    
    // 남아있는 스택 원소들을 전부 문자열로 붙여줌
    return stack.reduce("") { $0 + "\($1)"}
}