#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//간선 정보 클래스
class Edge {
public:
	int vtx[2]; //연결된 2개의 정점
	int dist; //거리;

	Edge(int a, int b, int dist) {
		this->vtx[0] = a;
		this->vtx[1] = b;
		this->dist = dist;
	}

	//정렬 조건 거리의 올림차순
	bool operator < (Edge& e) {
		return this->dist < e.dist;
	}
};

//재귀로 집합 찾기
int get_Set(int set[], int x) {
	if (set[x] == x)
		return x;
	return set[x] = get_Set(set, set[x]);
}

//두 집합 합치기
void union_Set(int set[], int a, int b) {
	a = get_Set(set, a);
	b = get_Set(set, b);

	if (a < b)
		set[b] = a;
	else
		set[a] = b;
	return;
}

//동일한 집합 내에 있는지 확인
int find_data_in_Set(int set[], int a, int b) {
	a = get_Set(set, a);
	b = get_Set(set, b);
	if (a == b)
		return 1;
	return 0;
}

int main(void) {
	int v;

	v = 9;

	vector<Edge> data;
	
	data.push_back({ 0,1,8 });
	data.push_back({ 0,2,12 });
	data.push_back({ 1,2,13 });
	data.push_back({ 1,3,25 });
	data.push_back({ 1,4,9 });
	data.push_back({ 2,3,14 });
	data.push_back({ 2,6,21 });
	data.push_back({ 3,4,20 });
	data.push_back({ 3,5,8 });
	data.push_back({ 3,6,12 });
	data.push_back({ 3,7,12 });
	data.push_back({ 3,8,16 });
	data.push_back({ 4,5,19 });
	data.push_back({ 5,7,11 });
	data.push_back({ 6,8,11 });
	data.push_back({ 7,8,9 });
	
	//정렬
	sort(data.begin(), data.end());

	int set[9];

	for (int i = 0; i < v; ++i) 
		set[i] = i;
	
	//최소비용
	int tot = 0;

	for (int i = 0; i < data.size(); ++i) {
		//사이클에 발생 X -> 그래프에 포함
		if (!find_data_in_Set(set, data[i].vtx[0], data[i].vtx[1])) {
			tot += data[i].dist;
			union_Set(set, data[i].vtx[0], data[i].vtx[1]);
		}
	}

	cout << tot;
	return 0;
}