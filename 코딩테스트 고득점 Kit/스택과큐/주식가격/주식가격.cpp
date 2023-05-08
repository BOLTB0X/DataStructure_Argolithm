#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> st;
    
    for (int i = 0; i < prices.size(); ++i) {
        // 스택이 비어있지 않고 현재보다 작다면
        while(!st.empty() && prices[st.top()] > prices[i]) {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    
    // 비어있지 않다면
    while(!st.empty()) {
        answer[st.top()] = prices.size() - st.top() - 1;
        st.pop();
    }
    return answer;
}