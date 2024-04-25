import Foundation

func solution(_ wallpaper:[String]) -> [Int] {
    var startX: Int = Int.max, startY: Int = Int.max
    var endX: Int = Int.min, endY: Int = Int.min
    let wallpaper = wallpaper.map { Array($0) }
    
    for i in wallpaper.indices {
        for j in wallpaper[i].indices {
            if wallpaper[i][j] == "#" {
                startX = min(i, startX)
                startY = min(j, startY)
                endX = max(i, endX)
                endY = max(j, endY)
            }
        }
    }
    
    return [startX, startY, endX + 1, endY + 1]
}