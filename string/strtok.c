#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char str[] = "ASD FEDF";  
	char* ptr = strtok(str, " ");


	printf("%s\n", ptr); //ASD

	return 0;
}