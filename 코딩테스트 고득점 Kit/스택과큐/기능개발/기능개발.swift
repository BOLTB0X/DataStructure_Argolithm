import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var answer:[Int] = [] // 정답 
    var _p = progresses // 편의용
    var _speeds = speeds // 편의용
    
    // 진도율 _p가 비어지기 전까지 무한루프
    while _p.count > 0 {
        var cnt: Int = 0 // 매 루프 == 배포 주기
        // 작업 시작
        for i in 0..<_speeds.count {
            _p[i] += _speeds[i] // 진도
        }
        ß
        // 이제 배포가능한 게 있는지 체크
        // 있으면 가장 최상단 부터 체크
        while _p.count > 0 && _p[0] >= 100 {
            _p.removeFirst() // 큐처럼 삭제
            _speeds.removeFirst() // 큐처럼 삭제
            cnt += 1 // 카운트
        }
        
        if cnt > 0 { // 배포된 것이 존재하면
            answer.append(cnt) // 정답에 push
        }
    }
    return answer
}