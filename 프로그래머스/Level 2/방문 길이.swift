// https://school.programmers.co.kr/learn/courses/30/lessons/49994
import Foundation

func solution(_ dirs:String) -> Int {
    var answer:Int = 0
    var visited:Set<[Int]> = []
    var cx = 0
    var cy = 0
    
    for dir in dirs {
        if dir == "U" && cx < 5 {
            visited.insert([cx, cy]+[cx+1, cy])
            cx += 1
        } else if dir == "D" && cx > -5 {
            visited.insert([cx-1, cy]+[cx, cy])
            cx -= 1
        } else if dir == "R" && cy < 5 {
            visited.insert([cx, cy]+[cx, cy+1])
            cy += 1
        } else if dir == "L" && cy > -5 {
            visited.insert([cx, cy-1]+[cx, cy])
            cy -= 1
        }
    }
    
    //print(visited)
    answer = visited.count
    
    return answer
}