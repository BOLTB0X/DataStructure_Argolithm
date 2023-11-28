import Foundation

func solution(_ v: [[Int]]) -> [Int]
{
    var ans:[Int] = [0,0]

    for i in 0..<2 {
        if v[0][i] == v[1][i] {
            ans[i] = v[2][i]
        } else if v[0][i] == v[2][i] {
            ans[i] = v[1][i]
        } else if v[1][i] == v[2][i] {
            ans[i] = v[0][i]
        }
    }
    
    return ans
}