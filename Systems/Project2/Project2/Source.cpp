#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct symbol_table_entry {
	char name;
	int address;
	int size;
};

struct IR_entry {
	int lineNo = 0;
	int opCode;
	int parameters[5];
};

struct symbol_table {
	struct symbol_table_entry* st[50];
	int numofVars = 0;
};

struct IR {
	struct IR_entry* IR_table[50];
	int numofinst = 0;
};

void read(struct IR* intermediate, char* line) {
	char command[5];
	char reg[3];
	sscanf(line, "%s %s", command, reg);
	struct IR_entry* ir = (struct IR_entry*)malloc(sizeof(struct IR_entry));
	ir->lineNo = intermediate->numofinst + 1;
	ir->opCode = 14;
	ir->parameters[0] = reg[0]-65;
	ir->parameters[1] = -1;
	printf("%d\n", ir->parameters[0]);
	intermediate->IR_table[intermediate->numofinst] = ir;
	intermediate->numofinst = intermediate->numofinst + 1;
}

void move(struct IR* intermediate, struct symbol_table* symbolTable,char* line) {
	char command[5];
	char reg[3];
	char var;
	sscanf(line, "%s %c,%s", command, &var, reg);
	struct IR_entry* ir = (struct IR_entry*)malloc(sizeof(struct IR_entry));
	ir->lineNo = intermediate->numofinst + 1;
	ir->opCode = 2;
	ir->parameters[0] = reg[0]-65;
	for (int j = 0;j < symbolTable->numofVars;j++) {
		if ((symbolTable->st[j])->name == var) {
			ir->parameters[1] = (symbolTable->st[j])->address;
			break;
		}
	}
	ir->parameters[2] = -1;
	printf("%d %d\n", ir->parameters[0], ir->parameters[1]);
	intermediate->IR_table[intermediate->numofinst] = ir;
	intermediate->numofinst = intermediate->numofinst + 1;
}

void add(struct IR* intermediate, char* line) {
	char command[5];
	char reg1[4];
	char reg2[4];
	char reg3[4];
	sscanf(line, "%s %s %s %s", command, reg1,reg2,reg3);
	struct IR_entry* ir = (struct IR_entry*)malloc(sizeof(struct IR_entry));
	ir->lineNo = intermediate->numofinst + 1;
	ir->opCode = 3;
	printf("%s %s %s %s\n", reg1,reg2,reg3);
	ir->parameters[0] = reg1[0]-65;
	ir->parameters[1] = reg2[0]-65;
	ir->parameters[2] = reg3[0]-65;
	ir->parameters[3] = -1;
	printf("%d %d %d\n", ir->parameters[0], ir->parameters[1], ir->parameters[2]);
	intermediate->IR_table[intermediate->numofinst] = ir;
	intermediate->numofinst = intermediate->numofinst + 1;
}

void print(struct IR* intermediate,struct symbol_table* symbolTable,char* line) {
	char command[6];
	char var;
	sscanf(line, "%s %c", command, &var);
	struct IR_entry* ir = (struct IR_entry*)malloc(sizeof(struct IR_entry));
	ir->lineNo = intermediate->numofinst + 1;
	ir->opCode = 13;
	for (int j = 0;j < symbolTable->numofVars;j++) {
		if ((symbolTable->st[j])->name == var) {
			ir->parameters[0] = (symbolTable->st[j])->address;
			break;
		}
	}
	ir->parameters[1] = -1;
	intermediate->IR_table[intermediate->numofinst] = ir;
	intermediate->numofinst = intermediate->numofinst + 1;
}

int processIf(struct IR* intermediate, char* line) {
	char label[5];
	char op1[3];
	char op2[3];
	char rel[5];
	char then[5];
	sscanf(line, "%s %s %s %s %s", label, op1, rel, op2,then);
	struct IR_entry* ir = (struct IR_entry*)malloc(sizeof(struct IR_entry));
	ir->lineNo = intermediate->numofinst + 1;
	ir->opCode = 7;
	ir->parameters[0] = op1[0] - 65;
	ir->parameters[1] = op2[0] - 65;
	if(strcmp(rel,"EQ"))
		ir->parameters[2] = 8;
	if (strcmp(rel, "LT"))
		ir->parameters[2] = 9;
	if (strcmp(rel, "GT"))
		ir->parameters[2] = 10;
	if (strcmp(rel, "LTEQ"))
		ir->parameters[2] = 11;
	if (strcmp(rel, "GTEQ"))
		ir->parameters[2] = 12;
	ir->parameters[3] = -1;
	printf("%d %d %d\n", ir->parameters[0], ir->parameters[1], ir->parameters[2]);
	intermediate->IR_table[intermediate->numofinst] = ir;
	intermediate->numofinst = intermediate->numofinst + 1;
	return ir->lineNo;
}
int processElse(struct IR* intermediate) {
	struct IR_entry* ir = (struct IR_entry*)malloc(sizeof(struct IR_entry));
	ir->lineNo = intermediate->numofinst + 1;
	ir->opCode = 6;
	ir->parameters[0] = -1;
	intermediate->IR_table[intermediate->numofinst] = ir;
	intermediate->numofinst = intermediate->numofinst + 1;
	return ir->lineNo;
}


void writeFile(struct IR* intermediate) {
	FILE* out = fopen("output.txt", "w");
	struct IR_entry* ir = (struct IR_entry*)malloc(sizeof(struct IR_entry));
	for (int i = 0;i < intermediate->numofinst;i++) {
		ir = intermediate->IR_table[i];
		fprintf(out, "%d %d ", ir->lineNo, ir->opCode);
		int j = 0;
		while (ir->parameters[j] != -1) {
			fprintf(out, "%d ", ir->parameters[j]);
			j++;
		}
		fprintf(out, "\n");
	}
	fclose(out);
}

int main() {
	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("file doesn't exist\n");
		return 0;
	}
	int top = -1;
	int stack[10];
	char line[128];
	struct symbol_table symbolTable;
	symbolTable.numofVars = 0;
	while (fgets(line, sizeof line, fp) != NULL && strstr(line, "START") == NULL) {
		struct symbol_table_entry* d = (struct symbol_table_entry*)malloc(sizeof(struct symbol_table_entry));
		d->name = line[5];
		d->size = 1;
		if (line[6] == '[')
			d->size = line[7] - '0';
		if (symbolTable.numofVars == 0)
			d->address = 0;
		else
			d->address = (symbolTable.st[symbolTable.numofVars - 1])->size + (symbolTable.st[symbolTable.numofVars - 1])->address;
		symbolTable.st[symbolTable.numofVars] = d;
		symbolTable.numofVars = symbolTable.numofVars + 1;
	}
	struct IR intermediate;
	intermediate.numofinst = 0;
	while (fgets(line, sizeof line, fp) != NULL && strstr(line, "END") == NULL) {
		char command[10];
		char param[20];
		sscanf(line, "%s %s", command, param);
		if (strcmp(command, "READ")==0) {
			read(&intermediate,line);
		}
		else if (strcmp(command, "MOV")==0) {
			move(&intermediate, &symbolTable, line);
		}
		else if (strcmp(command, "ADD")==0) {
			add(&intermediate,line);
		}
		else if (strcmp(command, "PRINT")==0) {
			print(&intermediate, &symbolTable,line);
		}
		else if (strcmp(command, "IF") == 0) {
			top++;
			stack[top] = processIf(&intermediate, line);
		}
		else if (strcmp(command, "ELSE") == 0) {
			top++;
			stack[top] = processElse(&intermediate);
		}
		else if (strcmp(command, "ENDIF") == 0) {
			top++;
			stack[top] = intermediate.numofinst;
		}
	}

	fclose(fp);
	writeFile(&intermediate);
	return 0;
}