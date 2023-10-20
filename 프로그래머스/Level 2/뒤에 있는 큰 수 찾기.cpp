// https://school.programmers.co.kr/learn/courses/30/lessons/154539
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    vector<int> stack;
    
    for (int i = 0; i < numbers.size(); ++i) {
        while(!stack.empty() && numbers[stack.back()] < numbers[i]) {
            answer[stack.back()] = numbers[i];
            stack.pop_back();
        }
        stack.push_back(i);
    }
    return answer;
}