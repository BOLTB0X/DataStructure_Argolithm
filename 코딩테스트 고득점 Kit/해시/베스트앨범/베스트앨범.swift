import Foundation

func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    var answer:[Int] = []
    var totalDic: [String:Int] = [:]
    var indexDic:[String: [Int]] = [:]
    
    for i in 0..<genres.count {
        if let _ = totalDic[genres[i]] {
            totalDic[genres[i]]? += plays[i]
            indexDic[genres[i]]?.append(i)
        } else {
            totalDic[genres[i]] = plays[i]
            indexDic[genres[i]] = [i]
        }
    }
    
    //print(totalDic)
    //print(indexDic)
    let sortedTotalDic = totalDic.sorted {$0.value > $1.value}
    
    for (key, value) in sortedTotalDic {
        let sortedArr = indexDic[key]!.sorted { plays[$0] > plays[$1]}
        answer.append(sortedArr[0])
        if sortedArr.count > 1 {
            answer.append(sortedArr[1])
        }
    }
    
    return answer
}