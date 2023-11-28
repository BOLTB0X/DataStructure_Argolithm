import Foundation

let n = Int(readLine()!)!

for i in 0..<n {
    for j in 0..<i+1 {
        print("*", terminator: "")
    }
    print()
}


