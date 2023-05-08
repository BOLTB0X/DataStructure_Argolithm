#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s) {
    bool answer = true;
    stack<char> st;
    
    for (auto & p : s) {
        if (p == '(') 
            st.push(p);
        else {
            if (st.empty())
                return false;
            else if (st.top() == '(')
                st.pop();
        }
    }
    
    if (!st.empty())
        answer = false;
    else {
        answer = true;
    }

    return answer;
}