import UIKit

var arr = [[1,2,3], [4,5,6],[7,8,9]]
var tmp = Array(repeating: Array(repeating: 0, count: 3), count: 3)

func roatateArray(_ n:Int) {
    for i in 0..<n {
        for j in 0..<n {
            tmp[i][j] = arr[n-1-j][i]
        }
    }
    
    for i in 0..<n {
        for j in 0..<n {
            arr[i][j] = tmp[i][j]
        }
    }
}

func ReverseRoatateArray(_ n:Int) {
    for i in 0..<n {
        for j in 0..<n {
            //tmp[j][i] = arr[i][n-1-j]
            tmp[i][j] = arr[j][n-1-i]
        }
    }
    
    for i in 0..<n {
        for j in 0..<n {
            arr[i][j] = tmp[i][j]
        }
    }
}

for i in 0..<3 {
    print(arr[i])
//    [1, 2, 3]
//    [4, 5, 6]
//    [7, 8, 9]
}
print("-----------------------------")
//roatateArray(3)
ReverseRoatateArray(3)

for i in 0..<3 {
    print(arr[i])
//    [7, 4, 1]
//    [8, 5, 2]
//    [9, 6, 3]
}

print("-----------------------------")
