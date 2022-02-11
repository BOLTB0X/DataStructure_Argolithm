#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int tran_dec(string number, int a) {
	int size = number.size();
	int tot = 0;
	
	for (int i = size - 1, j = 1; i >= 0; ++i, j *= a) {
		if (number[i] >= 'A')
			number[i] = '9' + (number[i] - 'A') + 1;
		tot += j * (number[i] - '0');
	}
	
	return tot;
}

string trans_b(int number, int b) {
	string n= "";

	while (number > 0) {
		if (number % b > 9)
			n += (number % b) - 10 + 'A';
		else
			n += (number % b) + '0';
	}

	reverse(n.begin(), n.end());

	return n;
}

int main(void) {
	int number = 124334;



	return 0;
}