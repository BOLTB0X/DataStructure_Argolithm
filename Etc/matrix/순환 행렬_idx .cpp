#include <iostream>

using namespace std;

struct NODE {
	int y, x;
};

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

int main(void) {
	NODE cur = { 3,3 };
	cout << "기본\n";
	cout << cur.y << ' ' << cur.x << '\n';
	//상
	cur.y = (cur.y + 2 * dy[0] + 10) % 10;
	cur.x = (cur.x + 2 * dx[0] + 10) % 10;
	// 위로 2칸 이동
	cout << "위로 2칸 이동\n";
	cout << cur.y << ' ' << cur.x << '\n';
	//하 
	cur.y = (cur.y + 6 * dy[1] + 10) % 10;
	cur.x = (cur.x + 6 * dx[1] + 10) % 10;
	// 아래로 6칸 이동
	cout << "아래로 6칸 이동\n";
	cout << cur.y << ' ' << cur.x << '\n';
	//좌 
	cur.y = (cur.y + 12 * dy[2] + 10) % 10;
	cur.x = (cur.x + 12 * dx[2] + 10) % 10;
	// 좌로 12칸 이동
	cout << "좌로 12칸 이동\n";
	cout << cur.y << ' ' << cur.x << '\n';//하 
	cur.y = (cur.y + 21 * dy[3] + 10) % 10;
	cur.x = (cur.x + 21 * dx[3] + 10) % 10;
	// 우로 21칸 이동
	cout << "우로 21칸 이동\n";
	cout << cur.y << ' ' << cur.x << '\n';

}
