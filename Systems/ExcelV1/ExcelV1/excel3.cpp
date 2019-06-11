#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"

struct node {
	//int data;
	char* expression;
};

int stringToInt(char* s) {
	int x;
	sscanf(s, "%d", &x);
	return x;
}

int solve(int a, int b, char op) {
	switch (op) {
		case('+'):return(a + b);
		case('-'):return(a - b);
		case('*'):return(a*b);
		case('/'):return(a / b);
		case('%'):return(a%b);
	}
	return 0;
}

int get(struct node* cells[][10], char* arg) {
	int row = arg[1] - '0' - 1;
	int col = arg[0] - 65;
	char op;
	int a,b;
	int i = 3;
	if (strcmp(arg, "0") == 0)
		return 0;
	char *exp = cells[row][col]->expression;
	if (strcmp(exp, "0") == 0)
		return 0;
	if (isalpha(exp[i])) {
		a = get(cells, exp + 3);
		i=5;
		if (exp[i] == '\0')
			return(a);
	}
	else {
		char* num = exp + 3;
		while (isdigit(exp[i]))
			i++;
		num[i - 3] = '\0';
		a = stringToInt(num);
		if (exp[i] == '\0')
			return(a);
	}
	op = exp[i];
	i++;
	int k = i;
	if (isalpha(exp[i])) {
		b = get(cells, exp + i);
		i += 2;
	}
	else {
		while (isdigit(exp[i])) {
			i++;
		}
		b = stringToInt(exp + k);
	}
	return(solve(a, b, op));
}

void importFile(char* fileName, struct node* cells[][10]) {
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
		char* token;
		token = strtok(line, ",");
		j = 0;
		int s;
		while (token != NULL) {
			cells[i][j]->expression = token;
			//printf("%d ", arr[i][j]);
			token = strtok(NULL, ",");
			j++;
		}
		//printf("\n");
		i++;
	}
	fclose(fp);
}

void Export(char* fileName, struct node* cells[][10]) {
	if (!strstr(fileName, ".csv"))
		fileName = strcat(fileName, ".csv");
	FILE *fp = fopen(fileName, "w");
	if (fp == NULL) {
		printf("File does not exist.\n");
		return;
	}
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			fprintf(fp, "%s,", cells[i][j]->expression);
		}
		fprintf(fp, "%s", "\n");
	}
	fclose(fp);
}

bool checkGet(struct node* cells[][10], int c1, int r1, int c0, int r0) {
	if (c0 == c1 && r0 == r1)
		return true;
	char* arg = cells[r1 - 1][c1]->expression;
	int i = 3;
	while (i < strlen(arg)) {
		if (isalpha(arg[i])) {
			if (checkGet(cells, arg[i] - 65, arg[i + 1] - '0', c0, r0)) 
				return true;
			i++;
		}
		i++;
	}
	return false;
}

void set(struct node* cells[][10], char* arg) {
	int row = arg[1] - '0';
	int col = arg[0] - 65;
	int i = 3;
	while(i< strlen(arg)) {
		if (isalpha(arg[i])) {
			if (checkGet(cells, arg[i]-65, arg[i + 1]-'0', arg[0]-65, arg[1]-'0')) {
				printf("Expression not valid\n");
				return;
			}
			i++;
		}
		i++;
	}
	cells[row - 1][col]->expression = arg;
}

int main() {
	struct node* cells[10][10];
	for (int i = 0;i < 10;i++)
		for (int j = 0;j < 10;j++) {
			struct node* n = (struct node*)malloc(sizeof(struct node));
			char exp[20] = "0";
			n->expression = exp;
			cells[i][j] = n;
		}
	char* lastImport = (char*)malloc(20);
	while (1) {
		printf(">");
		char* command = (char*)malloc(20);
		fgets(command, 20, stdin);
		if (strstr(command, "EXIT") != NULL)
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
				importFile(strtok(arg, "\n"), cells);
				lastImport = strtok(arg, "\n");
			}
			else if (strstr(command, "EXPORT") != NULL) {
				Export(strtok(arg, "\n"), cells);
			}
			
			if (strstr(command, "GET") != NULL) {
				int x = get(cells, arg);
				printf("%d\n", x);
			}
			else if (strstr(command, "SET") != NULL) {
				set(cells, arg);
			}
			
			else if (strstr(command, "SAVE") != NULL) {
				Export(lastImport, cells);
			}
			
		}
		if (strstr(command, "PRINT") != NULL) {
			for (int i = 0;i < 10;i++) {
				for (int j = 0;j < 10;j++)
					printf("%d ", get(cells, cells[i][j]->expression));
				printf("\n");
			}
		}
	}
}