#include <iostream>

using namespace std;

struct NODE {
	int y, x;
};

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

int main(void) {

	NODE cur = { 3,3 };
	cout << "±âº»\n";
	cout << cur.y << ' ' << cur.x << '\n';
	//»ó
	cur.y = (cur.y + 2 * dy[0] + 10) % 10;
	cur.x = (cur.x + 2 * dx[0] + 10) % 10;
	// À§·Î 2Ä­ ÀÌµ¿
	cout << "À§·Î 2Ä­ ÀÌµ¿\n";
	cout << cur.y << ' ' << cur.x << '\n';
	//ÇÏ 
	cur.y = (cur.y + 6 * dy[1] + 10) % 10;
	cur.x = (cur.x + 6 * dx[1] + 10) % 10;
	// ¾Æ·¡·Î 6Ä­ ÀÌµ¿
	cout << "¾Æ·¡·Î 6Ä­ ÀÌµ¿\n";
	cout << cur.y << ' ' << cur.x << '\n';
	//ÁÂ 
	cur.y = (cur.y + 12 * dy[2] + 10) % 10;
	cur.x = (cur.x + 12 * dx[2] + 10) % 10;
	// ÁÂ·Î 12Ä­ ÀÌµ¿
	cout << "ÁÂ·Î 12Ä­ ÀÌµ¿\n";
	cout << cur.y << ' ' << cur.x << '\n';//ÇÏ 
	cur.y = (cur.y + 21 * dy[3] + 10) % 10;
	cur.x = (cur.x + 21 * dx[3] + 10) % 10;
	// ¿ì·Î 21Ä­ ÀÌµ¿
	cout << "¿ì·Î 21Ä­ ÀÌµ¿\n";
	cout << cur.y << ' ' << cur.x << '\n';

}