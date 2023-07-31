#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    
    for (int a : arr) {
        // 비어있으면 넣으셈
        if (st.empty()) {
            st.push(a);
            answer.push_back(a);
        }
        
        else {
            // 스택의 최상단과 같다면
            // 중복이므로 패스
            if (st.top() == a)
                continue;
            st.push(a);
            answer.push_back(a);
        }
    }

    return answer;
}