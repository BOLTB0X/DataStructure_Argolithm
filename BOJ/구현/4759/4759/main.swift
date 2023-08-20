//
//  main.swift
//  4759 비밀번호 발음
//
//  Created by KyungHeon Lee on 2023/08/20.
//

import Foundation


while true {
    let password = readLine()!
    
    if password == "end" {
        break
    } else {
        solution(password)
    }
}

func solution(_ password: String) {
    var password: [String] = password.map { String($0) }
    var cnt: Int = 0
    let moum: String = "aeiou"
    
    for p in password {
        if moum.contains(p) {
            cnt += 1
        }
    }
    
    // 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
    if cnt < 1 {
        print("<\(password.joined())> is not acceptable.")
        return
    } else {
        cnt = 0
        if password.count >= 3 {
            // 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
            for i in 0..<password.count-2 {
                if moum.contains(password[i]) && moum.contains(password[i+1]) && moum.contains(password[i+2]) {
                    cnt = 1
                    break
                } else if !moum.contains(password[i]) && !moum.contains(password[i+1]) && !moum.contains(password[i+2]) {
                    cnt = 1
                    break
                }
            }
        }
    }
    
    if cnt == 1 {
        print("<\(password.joined())> is not acceptable.")
        return
    } else {
        cnt = 0
        if password.count >= 2 {
            for i in 0..<password.count-1 {
                if password[i] == password[i+1] {
                    if password[i] == "e" || password[i] == "o" {
                        continue
                    }
                    cnt = 1
                }
            }
        }
    }
    
    if cnt == 1 {
        print("<\(password.joined())> is not acceptable.")
    } else {
        print("<\(password.joined())> is acceptable.")
    }
    
    return
}
