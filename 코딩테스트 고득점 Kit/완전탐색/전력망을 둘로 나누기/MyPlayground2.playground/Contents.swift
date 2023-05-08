import Foundation

// enumerated
let arr = [1,2,3,4,5,6]

for i in arr.enumerated() {
    print("\(i.offset) \(i.element)")
//    0 1
//    1 2
//    2 3
//    3 4
//    4 5
//    5 6
}

print("-------------------------------------")

for i in arr.enumerated() {
    print("\(i.0) \(i.1)")
//    0 1
//    1 2
//    2 3
//    3 4
//    4 5
//    5 6
}

print("-------------------------------------")

//MARK: 2차원 배열 for문 출력 결과

let mat = [[0,1,2,3],[4,5,6,7],[8,9,10,11],[12,13,14,15]]

for m in mat {
    print(m)
//    [0, 1, 2, 3]
//    [4, 5, 6, 7]
//    [8, 9, 10, 11]
//    [12, 13, 14, 15]
}

print("-------------------------------------")

for i in 0..<mat[3].count {
    print(mat[3][i])
//    12
//    13
//    14
//    15
}
