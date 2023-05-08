import Foundation

func solution(_ phone_book: [String]) -> Bool {
    var phone_book = phone_book // 편의용
    // 오름차순 정렬
    phone_book.sort{$0.count < $1.count}
    
    // 완전탐색으로 풀이
    for i in 0..<phone_book.count {
        for j in i+1..<phone_book.count {
            // hasPrefix: String(문자열)이 지정된 접두사로 시작하는지 여부를 Boolean 값으로 반환
            if phone_book[j].hasPrefix(phone_book[i]) {
                return false
            }
        }
    }
    return true
}