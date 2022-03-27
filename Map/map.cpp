#include <iostream>
#include <map>

using namespace std;

int main(void) {
	// Python�� dictionary�� ������ ����
	// size(), empty(), find(K), operator[k] (Ű k�� ���� ���� ���۷��� ����.Ű�� ������ Ű k�� ���� ���ο� ��Ʈ�� ����), 
	// insert(pair(k, v))(�� ��ġ�� ���� �ݺ��� ��ȯ), erase(k), erase(p) (�ݺ��� p�� ����Ű�� ��Ʈ�� ����), begin(), end()
	map<string, int> m; // map
	map<string, int>::iterator iter;

	m.insert({ "Rob", 28 });
	m.insert({ "Joe", 50 });
	m.insert({ "Sue", 75 });

	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "( " << iter->first << ", " << iter->second << " )" << '\n';
	// j R S

	m.erase(0);
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "( " << iter->first << ", " << iter->second << " )" << '\n';
	// R S
	return 0;
}