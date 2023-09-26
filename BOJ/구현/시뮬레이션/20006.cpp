// 20006 랭킹전 대기열
// https://www.acmicpc.net/problem/20006
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int p, m;
vector<vector<pair<int, string>>> rooms;

bool compare(pair<int,string> a, pair<int,string> b) {
    return a.second < b.second;
}

bool isPossibleJoin(int a, int b) {
    int diff = abs(a - b);
    return diff <= 10 ? true : false;
}

void roomSearch(int level, string nick) {
   if (rooms.empty())
   {
        vector<pair<int, string>> tempRoom;
        tempRoom.push_back({level, nick});
        rooms.push_back(tempRoom);
   } else {
        int flag = 0;
        for (int i = 0; i < rooms.size(); ++i)
        {
            if (rooms[i].size() == m) continue;

            if (isPossibleJoin(level, rooms[i].front().first)) {
                rooms[i].push_back({level, nick});
                flag = 1;
                break;
            } 
        }

        if (!flag)
        {
            vector<pair<int, string>> tempRoom;
            tempRoom.push_back({level, nick});
            rooms.push_back(tempRoom);
        }
   }
   
   return;
}
void roomPrint(void) {
    for (int i = 0; i < rooms.size(); ++i)
    {
        if (rooms[i].size() == m)
        {
            sort(rooms[i].begin(), rooms[i].end(), compare);
            cout << "Started!\n";
            for (auto& r: rooms[i])
            {
                cout << r.first << ' ' << r.second << "\n";
            }
        } else {
            sort(rooms[i].begin(), rooms[i].end(), compare);
            cout << "Waiting!\n";
            for (auto& r: rooms[i])
            {
                cout << r.first << ' ' << r.second << "\n";
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 

    int level;
    string nick;

    cin >> p >> m;
    for (int i = 0; i < p; ++i)
    {
        cin >> level >> nick;
        roomSearch(level, nick);
    }

    roomPrint();
    return 0;
}
