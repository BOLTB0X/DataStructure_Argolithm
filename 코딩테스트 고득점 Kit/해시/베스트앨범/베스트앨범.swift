import Foundation

func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    var answer:[Int] = []
    var totalDic: [String: Int] = [:]
    var idxDic:[String: [Int]] = [:]
    
    for i in 0..<genres.count {
        if let _ = totalDic[genres[i]] {
            totalDic[genres[i]]? += plays[i]
            idxDic[genres[i]]?.append(i)
        } else {
            totalDic[genres[i]] = plays[i]
            idxDic[genres[i]] = [i]
        }
    }
    
    //print(totalDic)
    //print(detailDic)

    let sortedTotalDic = totalDic.sorted { $0.value > $1.value}
    for (key, value) in sortedTotalDic {
        let sortedIdx = idxDic[key]!.sorted { plays[$0] > plays[$1]}
        //print(sortedIdx)
        answer.append(sortedIdx[0])
        if sortedIdx.count > 1 {
            answer.append(sortedIdx[1])
        }
    }
    
    return answer
}