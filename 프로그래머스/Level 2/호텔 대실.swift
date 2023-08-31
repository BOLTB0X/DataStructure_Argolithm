// https://school.programmers.co.kr/learn/courses/30/lessons/155651
import Foundation

func solution(_ book_time:[[String]]) -> Int {
    var answer:Int = 0
    var bookTime:[[Int]] = []
    var roomArr:[[Int]] = []
    
    func getTotalMinu(_ minu: String) -> Int {
        let splitedMin = minu.components(separatedBy: ":")
        
        return Int(splitedMin[0])!*60+Int(splitedMin[1])!
    }
    
    for book in book_time {
        let start = getTotalMinu(book[0])
        let end = getTotalMinu(book[1])
        bookTime.append([start, end])
    }
    
    bookTime.sort { $0[0] < $1[0] }

    
    for book in bookTime {
        if roomArr.isEmpty {
            roomArr.append(book)
        } else {
            var check:Bool = false
            for i in 0..<roomArr.count {
                if roomArr[i][1]+10 <= book[0] {
                    roomArr[i] = book
                    check = true
                    break
                }
            }
            if !check {
                roomArr.append(book)
            }
        }
    }
    
    answer = roomArr.count
    
    return answer
}