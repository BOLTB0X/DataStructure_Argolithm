#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int N= nums.size() / 2; // 길의 반
    
    // 중복을 없애기 위해 집합 이용
    set<int> selected;
    
    // 싹다 선택
    for (auto n: nums) {
        selected.insert(n);
    }
    
    answer = selected.size() <= N ? selected.size() : N;
    return answer;
}