import Foundation

import Foundation

func solution(_ n:Int, _ lost:[Int], _ reserve:[Int]) -> Int {
    var answer:Int = 0
    var students:[Int] = Array(repeating: 1, count: n+1)
    
    for r in reserve {
        students[r] += 1
    }
    
    for l in lost {
        students[l] -= 1
    }
    
    //print(students)
    
    for i in 1...n {
        if students[i] == 0 {
            if i > 1 && students[i-1] > 1{
                students[i-1] -= 1
                students[i] = 1
            } else if i < n && students[i+1] > 1 {
                students[i+1] -= 1
                students[i] = 1
            }
        }
    }
    
    //print(students)
    answer = students.filter { $0 >= 1}.count-1
    
    return answer
}