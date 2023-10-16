// https://school.programmers.co.kr/learn/courses/30/lessons/169198
#include <string>
#include <vector>

using namespace std;

int findMin(vector<int> v)
{
    int ret = v[0];
    for (int& n: v)
    {
        ret = n < ret ? n : ret;
    }
    return ret;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for (auto& ball : balls)
    {
        int res = 1001;
        int ex = ball[0], ey = ball[1];
        int diffX = startX - ex, diffY = startY - ey;
        
        int left = ((startX+ex)*(startX+ex)) + (diffY*diffY); // 왼쪽 쿠션
        int right = ((m-startX)+(m-ex))*((m-startX)+(m-ex)) + (diffY*diffY); // 오른쪽 쿠션
        int top = (diffX * diffX) + ((n - startY) + (n - ey)) * ((n - startY)+(n - ey));   // 위쪽 쿠션
        int bottom = (diffX * diffX) + ((startY + ey) * (startY + ey)); // 아래쪽 쿠션
        
        if (diffX == 0) // Y 축 같은 선상
        {
            if (diffY > 0)
            {
                res = findMin({left, right, top});
            } else
            {
                res = findMin({left, right, bottom});
            }
        }
        else if (diffY == 0) // X 축 같은 선상
        {
            if (diffX > 0)
            {
                res = findMin({right, top, bottom});
            } else
            {
                res = findMin({left, top, bottom});
            }
        }
        else
        {
            res = findMin({left, right, top, bottom});
        }
        
        answer.push_back(res);
    }
    return answer;
}