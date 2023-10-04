// 16173 점프왕 쩰리 (Small)
// https://www.acmicpc.net/problem/16173
#include <iostream>

using namespace std;
int n, board[3][3];

bool DFS(int x, int y){
    if(x == n-1 && y == n-1) return true;

    if(x >= n || y >= n) return false;

    bool flag = false;
    if(!flag && x + board[x][y] > x) flag = DFS(x + board[x][y], y);
    if(!flag && y + board[x][y] > y) flag =  DFS(x, board[x][y] + y);
    
    return flag;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
        cin >> board[i][j];

    if (DFS(0, 0)) cout << "HaruHaru";
    else cout << "Hing";

    return 0;
}