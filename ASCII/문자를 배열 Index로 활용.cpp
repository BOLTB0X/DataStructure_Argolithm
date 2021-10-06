#include<iostream>

using namespace std;

int main(void) {
	int arr[26];

	char ch = 'a';
	for (int i = 0; i < 26; ++i) {
		arr[ch - 97] = i;
		cout << (char)(i+65) << '\n';
	}
}