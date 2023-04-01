#include <iostream>

using namespace std;

int num = 50;
int prime[51];

void solution(void) {
	

	for (int i = 2; i <= num; ++i) 
		prime[i] = i;
	
	for (int i = 2; i * i <= num; ++i) {
		if (prime[i] == 0)
			continue;
		for (int j = i * i; j <= num; j += i)
			prime[j] = 0;
	}

	//0이 아니면 소수
	for (int i = 2; i <= num; ++i) {
		if (prime[i] != 0)
			cout << prime[i] << ' ';
	}
	return;
}
int main(void) {
	solution();
	return 0;
}