// https://school.programmers.co.kr/learn/courses/30/lessons/118667
#include <string>
#include <vector>
#include <queue>
#define LL long long

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0; 
    LL que1_Sum = 0, que2_Sum = 0;
    queue<int> que1, que2;
    
    for (int i = 0; i < queue1.size(); ++i) {
        que1.push(queue1[i]);
        que2.push(queue2[i]);
        que1_Sum += queue1[i];
        que2_Sum += queue2[i];
    }
    
    while(1) {
        if (answer > queue1.size() * 4) {
            answer = -1;
            break;
        }
        
        if (que1_Sum == que2_Sum) {
            break;
        }
        
        if (que1_Sum > que2_Sum) {
            que2.push(que1.front());
            que1_Sum -= que1.front();
            que2_Sum += que1.front();
            que1.pop();    
        }
            
        else if (que1_Sum < que2_Sum){
            que1.push(que2.front());
            que1_Sum += que2.front();
            que2_Sum -= que2.front();
            que2.pop();
        }
        
        answer++;
    }
    
    return answer;
}