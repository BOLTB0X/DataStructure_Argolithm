//
//  main.swift
//  1991 트리 순회
//  https://www.acmicpc.net/problem/1991
//  Created by KyungHeon Lee on 2023/07/25.
//

import Foundation

let N = Int(readLine()!)!
var tree: [String:[String]] = [:]
var answer: [String] = ["", "", ""]

for _ in 0..<N {
    let input = readLine()!.split { $0 == " " }.map { String($0) }
    tree[input[0]] = [input[1], input[2]]
}

DFS("A")

for ans in answer {
    print(ans)
}

//preorder("A")
//print()
//inorder("A")
//print()
//postorder("A")
//print()


// MARK: - DFS로 트리 순회(전위, 중위, 후위 한 번에)
func DFS(_ root: String) {
    if root == "." {
        return
    }
    
    // 전위
    answer[0] += root
    DFS(tree[root]![0])
    answer[1] += root
    DFS(tree[root]![1])
    answer[2] += root
}

// MARK: - 전위 순회
// (루트) (왼쪽 자식) (오른쪽 자식)
func preorder(_ root: String) {
    if root == "." {
        return
    }
    
    print(root, terminator: "")
    preorder(tree[root]![0])
    preorder(tree[root]![1])
}

// MARK: - 중위 순회
// (왼쪽 자식) (루트) (오른쪽 자식)
func inorder(_ root: String) {
    if root == "." {
        return
    }
    
    inorder(tree[root]![0])
    print(root, terminator: "")
    inorder(tree[root]![1])
}

// MARK: - 후위 순회
func postorder(_ root: String) {
    if root == "." {
        return
    }
    
    postorder(tree[root]![0])
    postorder(tree[root]![1])
    print(root, terminator: "")
}
