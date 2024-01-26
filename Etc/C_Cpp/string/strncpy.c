#include <stdio.h>
#include <string.h>
#include <malloc.h>

char* solution(char* phrases, int second) {
	char* answer = "";
	char tmp[] = "______________";

	strcat(tmp, phrases);
	char t;
	for (int i = 0; i < second; ++i) {
		for (int j = 0; j < strlen(tmp); ++j) {
			t = tmp[0];
			for (int k = 0; k < strlen(tmp) - 1; ++k) {
				tmp[k] = tmp[k + 1];
			}
			tmp[strlen(tmp) - 1] = t;
		}
	}

	return answer;
}