#include <iostream>

using namespace std;

struct NODE {
	int y, x;
};

const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,-1,1 };

int main(void) {

	NODE cur = { 3,3 };
	cout << "�⺻\n";
	cout << cur.y << ' ' << cur.x << '\n';
	//��
	cur.y = (cur.y + 2 * dy[0] + 10) % 10;
	cur.x = (cur.x + 2 * dx[0] + 10) % 10;
	// ���� 2ĭ �̵�
	cout << "���� 2ĭ �̵�\n";
	cout << cur.y << ' ' << cur.x << '\n';
	//�� 
	cur.y = (cur.y + 6 * dy[1] + 10) % 10;
	cur.x = (cur.x + 6 * dx[1] + 10) % 10;
	// �Ʒ��� 6ĭ �̵�
	cout << "�Ʒ��� 6ĭ �̵�\n";
	cout << cur.y << ' ' << cur.x << '\n';
	//�� 
	cur.y = (cur.y + 12 * dy[2] + 10) % 10;
	cur.x = (cur.x + 12 * dx[2] + 10) % 10;
	// �·� 12ĭ �̵�
	cout << "�·� 12ĭ �̵�\n";
	cout << cur.y << ' ' << cur.x << '\n';//�� 
	cur.y = (cur.y + 21 * dy[3] + 10) % 10;
	cur.x = (cur.x + 21 * dx[3] + 10) % 10;
	// ��� 21ĭ �̵�
	cout << "��� 21ĭ �̵�\n";
	cout << cur.y << ' ' << cur.x << '\n';

}