#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

bool isOperator(char c) {
	return(c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int precedence(char c) {
	if (c == '(')
		return 0;
	if (c == '*' || c == '/' || c == '%')
		return 2;
	return 1;
}

int solve(int a, int b, char op) {
	switch(op){
		case('+') : return(a + b);
		case('-') : return(a - b);
		case('*') : return(a * b);
		case('/') : return(a / b);
		case('%'): return(a % b);
	}
	return 0;
}

void evaluate(char* exp) {
	char op[20];
	int values[20];
	int to = -1, tv = -1;

	int i = 0,j,k,n;
	char* number = (char*)malloc(5);
	
	while (exp[i] != '\0') {
		//printf("%c*\n", exp[i]);
		j = 0;
		while(isdigit(exp[i]))
			number[j++] = exp[i++];
		if (j != 0) {
			i--;
			number[j] = '\0';
			sscanf(number, "%d", &n);
			tv++;
			values[tv] = n;
		}
		else if (isOperator(exp[i])) {
			while (to != -1 && precedence(op[to]) >= precedence(exp[i])) {
				k = solve(values[tv], values[tv-1], op[to]);
				to--;
				tv--;
				values[tv] = k;
			}
			to++;
			op[to] = exp[i];
		}
		else if(exp[i]=='('){
			to++;
			op[to] = exp[i];
		} 
		else if (exp[i] == ')') {
			while (op[to] != '(') {
				k = solve(values[tv], values[tv - 1], op[to]);
				to--;
				tv--;
				values[tv] = k;
			}
			to--;
		}
		i++;
	}

	while (to >= 0) {
		k = solve(values[tv], values[tv - 1], op[to]);
		to--;
		tv--;
		values[tv] = k;
	}
	printf("%d\n", values[tv]);
}

int main() {
	char exp[20] = "((1+9)*7)";
	evaluate(exp);
	return 0;
}
