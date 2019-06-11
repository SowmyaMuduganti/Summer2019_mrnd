#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
/*
struct node {
	int data;
	char* expression;
};

int stringToInt(char* s) {
	int x;
	sscanf(s, "%d", &x);
	return x;
}


int get(struct node* cells[][10], char* arg) {
	int row = arg[1] - '0';
	int col = arg[0] - 65;
	return(cells[row - 1][col]->data);
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
		char *token;
		token = strtok(line, ",");
		j = 0;
		while (token != NULL) {
			cells[i][j]->data = stringToInt(token);
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
			fprintf(fp, "%d,", cells[i][j]->data);
		}
		fprintf(fp, "%s", "\n");
	}
	fclose(fp);
}

bool isop(char c) {
	return(c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
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

int evaluate(char* exp,struct node* cells[][10]) {
	int i = 0;
	int a,b,j,k;
	char op;
	char num[5];

	if (isalpha(*(exp + i))) {
		a = get(cells, exp + i);
		op = *(exp + i + 2);
		i = i + 3;
	}
	else {
		j = 0;
		while (isdigit(*(exp + i))) {
			num[j++] = *(exp + i);
			i++;
		}
		num[j] = '\0';
		a = stringToInt(num);
		op = *(exp + i);
		i++;
	}
	if (isalpha(*(exp + i))) {
		b = get(cells, exp + i);
		i = i + 2;
	}
	else {
		j = 0;
		while (isdigit(*(exp + i))) {
			num[j++] = *(exp + i);
			i++;
		}
		num[j] = '\0';
		b = stringToInt(num);
	}
	//printf("%d %d %c\n", a, b, op);
	
	k = solve(a,b,op);
	return k;
}

void set(struct node* cells[][10], char* arg) {
	int row = arg[1] - '0';
	int col = arg[0] - 65;
	cells[row - 1][col]->expression = arg + 3;
	printf("%s\n", cells[row - 1][col]->expression);
	cells[row - 1][col]->data = evaluate(arg + 3,cells);
	char* cell = (char*)malloc(5);
	cell[0] = arg[0];
	cell[1] = arg[1];
	cell[2] = '\0';
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			if (strstr(cells[i][j]->expression, cell) != NULL)
				cells[i][j]->data = evaluate(cells[i][j]->expression, cells);
		}
	}
}
int main() {
	struct node* cells[10][10];
	for (int i = 0;i < 10;i++)
		for (int j = 0;j < 10;j++) {
			struct node* n = (struct node*)malloc(sizeof(struct node));
			n->data = 0;
			char exp[5] = "";
			n->expression = exp;
			cells[i][j] = n;
		}
	char* lastImport = (char*)malloc(20);
	while (1) {
		printf(">");
		char* command = (char*)malloc(20);
		fgets(command, 20, stdin);
		if (strstr(command, "PRINT") != NULL) {
			for (int i = 0;i < 10;i++)
				printf(" %c", 65 + i);
			for (int i = 0;i < 10;i++) {
				printf("\n%d ", i + 1);
				for (int j = 0;j < 10;j++)
					printf("%d ", cells[i][j]->data);
			}
			printf("\n");
		}
		else if (strstr(command, "EXIT") != NULL)
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
			else if (strstr(command, "GET") != NULL) {
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
	}
}*/