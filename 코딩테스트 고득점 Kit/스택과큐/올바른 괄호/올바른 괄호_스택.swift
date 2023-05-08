import Foundation

struct Stack<T> {
    private var stack: [T] = []
    
    public var size: Int {
        return stack.count
    }
    
    public var isEmpty: Bool {
        return stack.isEmpty
    }
    
    public mutating func push(_ element: T) {
        stack.append(element)
    }
    
    public mutating func pop() -> T? {
        return stack.popLast()
    }
    
    public mutating func top() -> T? {
        return stack.last
    }
}

func solution(_ s:String) -> Bool {
    var stack = Stack<Int>() // 스택
    
    for i in s {
        // open이면
        if i == "(" {
            stack.push(1) // 스택에 넣어줌
        } else { // close를 직면하는 경우
            // 스택이 비어있지 않고 open이 있는 경우
            if stack.isEmpty == true {
                return false
            } else {
                stack.pop()
            }
        }
    }
    
    if stack.isEmpty == false {
        return false
    }
    return true
}