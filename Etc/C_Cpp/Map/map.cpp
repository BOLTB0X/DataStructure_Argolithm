#include <iostream>
#include <map>

using namespace std;

int main(void) {
	// Python의 dictionary와 동일한 개념
	// size(), empty(), find(K), operator[k] (키 k의 값에 대한 레퍼런스 생성.키가 없으면 키 k를 갖는 새로운 엔트리 생성), 
	// insert(pair(k, v))(그 위치에 대한 반복자 반환), erase(k), erase(p) (반복자 p가 가리키는 엔트리 삭제), begin(), end()
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