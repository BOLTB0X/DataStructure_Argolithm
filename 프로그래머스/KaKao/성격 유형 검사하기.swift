// 2022 KAKAO TECH INTERNSHIP 성격 유형 검사하기
iimport Foundation

func solution(_ survey:[String], _ choices:[Int]) -> String {
    var answer:String = ""
    let choicesScore:[Int] = [0, 3, 2, 1, 0, 1, 2, 3]
    var typeDic:[String:Int] = ["R": 0, "T": 0, "C":0, "F": 0, "J": 0, "M": 0, "A": 0, "N": 0]
    
    for (i, s) in survey.enumerated() {
        let splitedS = s.map{ String($0) }
        if choices[i] == 4 {
            continue
        } else if choices[i] > 4 { // 동의
            typeDic[splitedS[1]]! += choicesScore[choices[i]]
        } else {
            typeDic[splitedS[0]]! += choicesScore[choices[i]]
        }
        //print(i, splitedS)
    }
    
    //print(typeDic)
    
    for jipyo in ["RT", "CF", "JM", "AN"] {
        let a = String(jipyo.first!)
        let b = String(jipyo.last!)
        
        if typeDic[a]! < typeDic[b]! {
            answer += b
        } else {
            answer += a
        }
    }
    
    return answer
}