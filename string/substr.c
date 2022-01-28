#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* substr(char* s, int start_idx, int cnt) {
	char* tmp = malloc(sizeof(char) * (cnt + 1));
	strncpy(tmp, s + start_idx, cnt);
	tmp[cnt] = 0;

	return tmp;
}

int main(void) {
	char* s2 = "ababc";
	char* s1 = "abcdab";

	char* tmp1 = substr(s1, 0, 4);
	char* tmp2 = substr(s2, strlen(s2) - 4, 4);

	printf("tmp1: %s\n", tmp1);
	printf("tmp2: %s\n", tmp2);

	return 0;
}

int solution(char* s1, char* s2) {
	int answer = 0;
	int s1_len = strlen(s1);
	int s2_len = strlen(s2);
	int target;

	if (s1_len < s2_len) {
		for (int i = 1; i <= s1_len; ++i) {
			char* tmp1 = substr(s1, strlen(s1) - i, i);
			char* tmp2 = substr(s2, 0, i);

			if (strcmp(tmp1, tmp2) == 0)
				target = i;
		}
	}
	else {
		for (int i = 1; i <= s2_len; ++i) {
			char* tmp1 = substr(s1, 0, i);
			char* tmp2 = substr(s2, strlen(s2) - i, i);

			if (strcmp(tmp1, tmp2) == 0)
				target = i;
		}
	}

	answer = s1_len + s2_len - target;
	return answer;
}