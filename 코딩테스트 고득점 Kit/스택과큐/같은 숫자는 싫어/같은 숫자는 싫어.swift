import Foundation

func solution(_ arr: [Int]) -> [Int] {
    var answer:[Int] = [] // 정답 
    var stack:[Int] = [] // 스택

    // 단순풀이
    for i in 0..<arr.count {
        if stack.count == 0 {
            st.append(arr[i])
            answer.append(arr[i])
        } else { 
            // 같은 숫자를 보면
            if st.last == arr[i] {
                continue
            }
            // 다른 숫자이니 넣어줌
            st.append(arr[i])
            answer.append(arr[i])
        }
    }
    return answer
}