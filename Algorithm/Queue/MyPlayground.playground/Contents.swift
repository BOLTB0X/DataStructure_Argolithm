import UIKit

// MARK: 큐
class Queue<T> {
    var enQueue: [T]
    var deQueue: [T] = []
    
    // MARK: 큐의 길이 반환
    var count: Int {
        return enQueue.count + deQueue.count
    }
    
    // MARK: 큐가 비었는지 체크
    var isEmpty: Bool {
        return enQueue.isEmpty && deQueue.isEmpty
    }
    
    init(_ queue: [T]) {
        self.enQueue = queue
    }
    
    // MARK: push
    func push(_ element: T) {
        enQueue.append(element)
    }
    
    // MARK: pop
    func pop() -> T {
        if deQueue.isEmpty {
            deQueue = enQueue.reversed()
            enQueue.removeAll()
        }
        return deQueue.popLast()!
    }
    
}

