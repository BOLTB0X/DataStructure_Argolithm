// 19637 IF문 좀 대신 써줘
// https://www.acmicpc.net/problem/19637
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, string>> styles;

int binarySearch(int target) {
    int res = -1, left = 0, right = N-1;

    while (left <= right)
    {
        int mid = (left+right) / 2;

        if (styles[mid].first >= target) 
        {   
            res = mid;
            right = mid-1;
        }

        else
            left = mid + 1;
    }
    
    return res;
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string str;
    int val;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) 
    {
        cin >> str >> val;
        styles.push_back({val, str});
    }

    //sort(styles.begin(), styles.end());

    for (int i = 0; i < M; ++i) 
    {
        cin >> val;
        int ret = binarySearch(val);

        cout << styles[ret].second << "\n";
    }


    return 0;
}