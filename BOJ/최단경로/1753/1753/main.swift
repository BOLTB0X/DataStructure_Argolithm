//
//  main.swift
//  1753 최단경로
//  https://www.acmicpc.net/problem/1753
//  Created by KyungHeon Lee on 2023/09/07.
//

import Foundation

public struct Heap<T> {
  var nodes: [T] = []
  let comparer: (T,T) -> Bool

  var isEmpty: Bool {
      return nodes.isEmpty
  }

  init(comparer: @escaping (T,T) -> Bool) {
      self.comparer = comparer
  }

  func peek() -> T? {
      return nodes.first
  }

  mutating func insert(_ element: T) {
      var index = nodes.count

      nodes.append(element)

      while index > 0, !comparer(nodes[index],nodes[(index-1)/2]) {
          nodes.swapAt(index, (index-1)/2)
          index = (index-1)/2
      }
  }

  mutating func delete() -> T? {
      guard !nodes.isEmpty else {
          return nil
      }

      if nodes.count == 1 {
          return nodes.removeFirst()
      }

      let result = nodes.first
      nodes.swapAt(0, nodes.count-1)
      _ = nodes.popLast()

      var index = 0

      while index < nodes.count {
          let left = index * 2 + 1
          let right = left + 1

          if right < nodes.count {
              if comparer(nodes[left], nodes[right]),
                  !comparer(nodes[right], nodes[index]) {
                  nodes.swapAt(right, index)
                  index = right
              } else if !comparer(nodes[left], nodes[index]){
                  nodes.swapAt(left, index)
                  index = left
              } else {
                  break
              }
          } else if left < nodes.count {
              if !comparer(nodes[left], nodes[index]) {
                  nodes.swapAt(left, index)
                  index = left
              } else {
                  break
              }
          } else {
              break
          }
      }

      return result
  }
}

extension Heap where T: Comparable {
    init() {
        self.init(comparer: >)
    }
}

struct EdgeData : Comparable{
    static func < (lhs: EdgeData, rhs: EdgeData) -> Bool {
        lhs.cost < rhs.cost
    }
    
    var cost : Int
    var node : Int
}


let input1 = readLine()!.split(separator: " ").map { Int(String($0))! }
let input2 = Int(readLine()!)!
var input3:[[Int]] = []

for _ in 0..<input1[1] {
    input3.append(readLine()!.split(separator: " ").map { Int(String($0))! })
}

let ret = solution(input1[0], input1[1], input2, input3)

for r in ret {
    print(r)
}

func solution(_ V: Int, _ E: Int, _ K: Int, _ graphInfo: [[Int]]) -> [String] {
    var answer:[String] = []
    var adj = Array(repeating: [(Int, Int)](), count: V+1)
    
    func dijikstra(_ start: Int) {
        var pq: Heap = Heap<EdgeData>()
        var idx:Int = 0
        var dist: [Int] = Array(repeating: Int.max, count: V+1)
        
        pq.insert(EdgeData(cost: 0,node: start))
        dist[start] = 0
        
        while !pq.isEmpty {
            let cur = pq.delete()!
            
            if dist[cur.node] < cur.cost {
                continue
            }
            
            for next in adj[cur.node] {
                let newCost = cur.cost + next.1
                
                if newCost < dist[next.0] {
                    dist[next.0] = newCost
                    pq.insert(EdgeData(cost: newCost, node: next.0))
                    
                }
            }
        }
        
        answer = dist[1...V].map {
            if $0 == Int.max {
                return "INF"
            } else {
                return String($0)
            }
        }
        
        return
    }
    
    for info in graphInfo {
        adj[info[0]].append((info[1], info[2]))
    }
    
    dijikstra(K)
    
    
    return answer
}
