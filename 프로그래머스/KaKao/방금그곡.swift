// 2018 KAKAO BLIND RECRUITMENT [3차] 방금그곡
import Foundation

func solution(_ m:String, _ musicinfos:[String]) -> String {
    var answer:String = "(None)"
    var m = m.replaceM()
    var ansTime:Int = 0

    for musicinfo in musicinfos {
        let splitedM = musicinfo.customComponents()
        //print(splitedM)
        let mellody = makeMellody(mellody: splitedM[2], t: Int(splitedM[0])!)
        //print(mellody)
        
        if m.contains(mellody) || mellody.contains(m) {
            if ansTime < Int(splitedM[0])! {
                answer = splitedM[1]
                ansTime = Int(splitedM[0])!
            }
        }
    }
    return answer
}
    
func makeMellody(mellody: String, t: Int) -> String {
    var ret:String = ""
    let cnt = ceil(Double(t)/Double(mellody.count))
    
    for _ in 0..<Int(cnt) {
        ret += mellody
    }
    
    return ret.map{String($0)}[0..<t].joined()
}

extension String {
    func replaceM() -> String {
        return self.replacingOccurrences(of: "C#", with: "c")
        .replacingOccurrences(of: "D#", with: "d")
        .replacingOccurrences(of: "F#", with: "f")
        .replacingOccurrences(of: "G#", with: "g")
        .replacingOccurrences(of: "A#", with: "a")
    }
    
    func customComponents() -> [String] {
        let strArr = self.components(separatedBy: ",")
        let t1 = strArr[0].components(separatedBy: ":")
        let t2 = strArr[1].components(separatedBy: ":")
        
        let newT1 = Int(t1[0])!*60 + Int(t1[1])!
        let newT2 = Int(t2[0])!*60 + Int(t2[1])!
        
        return [String(newT2-newT1), strArr[2], strArr[3].replaceM()]
    }
}