import Foundation

func solution(_ priorities:[Int], _ location:Int) -> Int {
    var answer:Int = 0
    // enumerated으로 인덱스와 값을 구분짓고 배열로 바꿈
    var que = priorities.enumerated().map{ ($0.offset, $0.element)} 
    var pq = priorities.sorted(by: >) // 우선순위 큐
    
    // 큐가 비어질때 까지
    // 큐가에 위치와 값과 중요도 pq를 내두고
    // 원소를 하나씩 pop해보면서 조건에 맞으면 카운트하고 
    // 아니면 회전시킴
    while que.isEmpty == false {
        // (int,int)이므로 편의를 위해
         let cur = que.removeFirst() 
        // 최상단과 중요도가 같다면
        if cur.1 == pq.first! {
            answer += 1 // 프린터하고 순번 카운트
            
            // 탈출 조건
            if cur.0 == location {
                break
            }
            
            // 가장 중요도 높은 문서 pop
            pq.removeFirst()
        } else {
            // 최상단을 가장 하단으로 넘겨줌
            que.append(cur)
        }
    }
    return answer
}