#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0, row, col;
    
    for (int i = 0; i < sizes.size(); ++i) {
        sort(sizes[i].begin(), sizes[i].end());
    }
    
    row = -1, col = -1;
    for (auto size: sizes) {
        if (row < size[1]) {
            row = size[1];
        }
        
        if (col < size[0]) {
            col = size[0];
        }
    }
    
    answer = row * col;
    return answer;
}