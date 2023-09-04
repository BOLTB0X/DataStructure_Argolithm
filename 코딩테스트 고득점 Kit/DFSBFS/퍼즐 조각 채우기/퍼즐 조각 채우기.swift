import Foundation

// 상좌하우
let dir = [(0,1),(0,-1),(1,0),(-1,0)]

func solution(_ game_board:[[Int]], _ table:[[Int]]) -> Int {
    var answer:Int = 0
    let N = table.count // 테이블의 갯수

    // 블록들이 테이블 위에 놓여져있으니 사용하기 불편
    // 그러므로 이차원 배열들로 따로 빼줘야함
    func blockList() -> [[(Int,Int)]] {
        var visited = Array(repeating: Array(repeating: false, count: N ), count: N )
        var blockList: [[(Int,Int)]] = []
        for i in 0..<N {
            for j in 0..<N {
                if visited[i][j] == false, table[i][j] == 1 {
                    visited[i][j] = true
                    var list: [(Int,Int)] = []
                    var queue = [(i,j)]
                    while !queue.isEmpty {
                        let f = queue.removeFirst()
                        list.append(f)
                        for k in 0..<4 {
                            let n = (f.0+dir[k].0, f.1+dir[k].1)
                            if n.0>=N||n.1>=N||n.0<0||n.1<0||visited[n.0][n.1]||table[n.0][n.1] == 0 { continue }
                            visited[n.0][n.1] = true
                            queue.append((n))
                        }
                    }
                    let f = list.first!
                    blockList.append(list.map{ ($0.0 - f.0, $0.1 - f.1)})
                }
            }
        }
        return blockList
    }

    func rotateBlockList() -> [[[(Int, Int)]]] {
        return blockList().map{ block -> [[(Int, Int)]] in
            var list: [[(Int,Int)]] = []
            list.append(block)
            var t = block.map{(-$0.1, $0.0)}
            list.append(t.map{ ($0.0 - t.first!.0, $0.1 - t.first!.1)})
            t = block.map{($0.1, -$0.0)}
            list.append(t.map{ ($0.0 - t.first!.0, $0.1 - t.first!.1)})
            t = block.map{(-$0.0, -$0.1)}
            list.append(t.map{ ($0.0 - t.first!.0, $0.1 - t.first!.1)})
            return list
        }
    }

    let blocks = rotateBlockList()
    answer = simulation(game_board, blocks, N)
    return answer
}

// 이제 보드에 블록을 넣고 시뮬레이션을 돌려봄
func simulation(_ game_board:[[Int]], _ blocks:[[[(Int, Int)]]], _ N:Int) -> Int {
    var total:Int = 0
    var board = game_board // 편의용
    var blocks = blocks // 편의용

    // 블록 방문리스트
    var blockVisited = Array(repeating: false, count: blocks.count)

    for i in 0..<N {
        for j in 0..<N {
            // 블록을 하나씩 확인
            for k in 0..<blocks.count {
                // 재방문인 경우
                if blockVisited[k] == true {
                    continue
                }
                 // 4방향 확인
                 for l in 0..<4 {
                    if board[i][j] == 0 {
                        let curBlock = blocks[k][l]
                        var flag = false

                        // 우선 넣어봄
                        curBlock.forEach {
                            let n = (i+$0.0, j+$0.1)
                            if n.0>=N||n.1>=N||n.0<0||n.1<0{
                                flag = true
                                return
                            } else if board[n.0][n.1] >= 1 {
                                flag = true
                                board[n.0][n.1] += 1
                            } else {
                                board[n.0][n.1] += 1
                            }
                        }

                        // 주변에 여백이있는지 확인
                        curBlock.forEach {
                            let n = (i+$0.0, j+$0.1)
                            if n.0>=N||n.1>=N||n.0<0||n.1<0 { 
                                return 
                            }
                                
                            for m in 0..<4 {
                                let nn = (n.0+dir[m].0, n.1+dir[m].1)
                                if nn.0>=N||nn.1>=N||nn.0<0||nn.1<0 {
                                    continue
                                }
                                if board[nn.0][nn.1] == 0 {
                                    flag = true
                                    break
                                }
                            }
                        }

                        // 실패했을 때 도형 회수
                        if flag == true {
                            curBlock.forEach {
                                let n = (i+$0.0, j + $0.1)
                                if n.0>=N||n.1>=N||n.0<0||n.1<0{ 
                                    return 
                                }
                                board[n.0][n.1] -= 1
                            }
                            continue
                        } else {
                            blockVisited[k] = true
                            total += curBlock.count
                            break
                        }
                    }
                }
            }
        }
    }
    return total
}