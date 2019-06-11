#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
/*
int stringToInt(char* s) {
	int x;
	sscanf(s, "%d", &x);
	return x;
}

void importFile(char* fileName, int arr[][10]) {
	if (!strstr(fileName, ".csv"))
		fileName = strcat(fileName, ".csv");
	FILE *fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("File does not exist.\n");
		return;
	}
	char line[128];
	int i, j;
	i = 0;
	while (fgets(line, sizeof line, fp) != NULL) {
		//fputs(line, stdout);
		char *token;
		token = strtok(line, ",");
		j = 0;
		while (token != NULL) {
			arr[i][j] = stringToInt(token);
			//printf("%d ", arr[i][j]);
			token = strtok(NULL, ",");
			j++;
		}
		//printf("\n");
		i++;
	}
	fclose(fp);
}

void export(char* fileName, int arr[][10]) {
	if (!strstr(fileName, ".csv")) 
		fileName = strcat(fileName, ".csv");
	FILE *fp = fopen(fileName, "w");
	if (fp == NULL) {
		printf("File does not exist.\n");
		return;
	}
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			fprintf(fp, "%d,", arr[i][j]);
		}
		fprintf(fp, "%s", "\n");
	}
	fclose(fp);
}

int main() {
	int arr[10][10] = { 0 };
	while (1) {
		printf(">");
		char* command = (char*)malloc(20);
		fgets(command, 20, stdin);
		if (strstr(command, "PRINT") != NULL) {
			for (int i = 0;i < 10;i++) {
				for (int j = 0;j < 10;j++)
					printf("%d ", arr[i][j]);
				printf("\n");
			}
		}
		else if (strstr(command, "EXIT")!=NULL)
			return 0;
		else {
			char *token;
			char *arg = (char*)malloc(20);
			token = strtok(command, " ");
			while (token != NULL) {
				arg = token;
				token = strtok(NULL, " ");
			}
			if (strstr(command, "IMPORT") != NULL) {
				importFile(strtok(arg, "\n"), arr);
			}
			else if (strstr(command, "EXPORT") != NULL) {
				export(strtok(arg, "\n"), arr);
			}
			else if (strstr(command, "GET") != NULL) {
				int row = arg[1] - '0';
				int col = arg[0] - 65;
				printf("%d\n",arr[row - 1][col]);
			}
			else if (strstr(command, "SET") != NULL) {
				int row = arg[1] - '0';
				int col = arg[0] - 65;
				arr[row - 1][col] = stringToInt(arg + 3);
			}
			else if (strstr(command, "PRINT") != NULL) {
				for (int i = 0;i < 10;i++) {
					for (int j = 0;j < 10;j++)
						printf("%d ", arr[i][j]);
					printf("\n");
				}
			}
		}
	}
}
*/