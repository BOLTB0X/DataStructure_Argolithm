// 1212 8진수 2진수
// https://www.acmicpc.net/problem/1212
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string X) {
    string answer = "";
    vector<int> stack;

    if (X == "0") return "0";

    for (int i = X.size()-1; i>=0; --i)
    {
        int tmp = X[i] - '0';
        for (int j = 0; j < 3; ++j)
        {
            stack.push_back(tmp % 2);
            tmp /= 2;
        }
    }

    while (stack.back() != 1) stack.pop_back();

    while (!stack.empty())
    {
        answer += to_string(stack.back());
        stack.pop_back();
    }
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string X;
	cin >> X;

	cout << solution(X);
	return 0;
}