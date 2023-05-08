#include <string>
#include <vector>

using namespace std;

void DFS(vector<int>& numbers, int target, int tot, int level, int &answer) {
    if (level == numbers.size()) {
        if (tot == target)
            answer++;
        return;
    }
    
    DFS(numbers, target, tot + numbers[level], level + 1, answer);
    DFS(numbers, target, tot - numbers[level], level + 1, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(numbers, target, 0, 0, answer);
    return answer;
}