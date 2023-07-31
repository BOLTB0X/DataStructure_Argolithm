import Foundation

func solution(_ n:Int, _ lost:[Int], _ reserve:[Int]) -> Int {
    var answer = 0
    // 학생들의 체육복 배열
    var students = [Int] (repeating: 1, count: n + 1)
    
    // 잃어버린 학생
    for l in lost {
        students[l] -= 1
    }
    
    // 여분
    for r in reserve {
        students[r] += 1
    }
    
    for i in 1..<n+1 {
        // 빌려야한 학생 발견
        if students[i] == 0 {
            // 앞에 학생에게 빌리는 경우
            if i > 1 && students[i - 1] > 1 {
                students[i - 1] -= 1
                students[i] = 1
            }
        
            // 뒤 애한테 빌리는 경우
            else if i < n && students[i + 1] > 1 {
                students[i + 1] -= 1
                students[i] = 1
            }
        }
    }
    
    answer = students.filter { $0 > 0 }.count // 수업가능한 학생 카운트
    return answer - 1 // 배열의 편의를 위해 인덱스 + 1 했기 때문
}