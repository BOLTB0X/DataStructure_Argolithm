import Foundation

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var answer = 0;
    // 방문리스트
    var visited = Array(repeating: false, count: dungeons.count);
    
    // MARK: 깊이우선탐색
    func DFS(_ cur:Int, _ level:Int) {
        // 던전 확인
        for i in 0..<dungeons.count {
            // 재방문인 경우
            if visited[i] == true {
                continue
            }
            
            // 현재 체력으로 최소필요피로도를 소화할수 없는 경우
            if cur < dungeons[i][0] {
                continue
            }
            
            var next = cur
            visited[i] = true
            answer = max(answer, level+1)
            DFS(next-dungeons[i][1], level+1)
            visited[i] = false
            
        }
    }
    
    DFS(k,0);
    
    return answer;
}


let k = 80
let dungeons = [[80,20],[50,40],[30,10]]

print(solution(k, dungeons))
