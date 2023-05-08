import Foundation

func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    var answer:[Int] = [] // 정답
    var dict:[String:[[Int]]] = [:] // 딕셔너리 생성
    // 문제 조건이 까다로운 편임
    // 먼저 속한 노래가 많이 재생된 장르
    // 장르 내에서 많이 재생된 노래 먼저 수록
    // 재생횟수가 같으면 idx가 낮은 것 부터
    
    // 처음에는 딕셔너리를 2개 생성(하나는 장르: 갯수, 나머진: 인덱스: 재생 횟수)를 생각했으니 생각이 꼬여서 하나의 딕셔너리에서 key(장르): value(인덱스,재생횟수)로 고침
    // 꼬였다는 것은 이를 다시 정렬해야하기 때문
    
    for i in genres.enumerated() {
        // 해당 장르가 있다면
        if let _ = dict[i.1] {
           dict[i.1]?.append([i.0, plays[i.0]])
        } else { // 없는 경우
            dict[i.1] = [[i.0, plays[i.0]]]
        }
    }
    
    // 이제 많이 재생된 장르 == 재생의 총 합을 기준으로 내림차순
    let sortedDict = dict.sorted{ (fir, sec) in
                                return fir.value.map {$0[1]}.reduce(0,+) > sec.value.map {$0[1]}.reduce(0,+)}
    
    // 이제 다시 많이 재생된 기준으로 내림차순
    // 만약 값이 같다면 인덱스가 작은 순으로
    for idx in 0..<sortedDict.count {
        // value [[Int]]
        let item = sortedDict[idx].value.sorted {
            (fir, sec) in return fir[1] == sec[1] ? false : fir[1] > sec[1]
        }
        
        for i in 0..<item.count {
            // 인덱스만 넣을 것이니
            if i > 1 {
                break
            }
            answer.append(item[i][0])
        }
        
    }
    
    return answer
}