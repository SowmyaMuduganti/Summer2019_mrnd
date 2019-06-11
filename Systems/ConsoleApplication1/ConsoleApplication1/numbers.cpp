#include "pch.h"
#include "header1.h"

void numbers(int n,int *arr, int k) {
	if (k == n) {
		int i = 0;
		while (arr[i] == 0)
			i++;
		if (i == n)
			return;
		while (i < k)
			printf("%d", arr[i++]);
		printf("\n");
		return;
	}
	for (int j=0;j<10;j++){
		arr[k] = j;
		numbers(n , arr, k + 1);
	}
}

char rev(int n) {
	char s[11]= "012E459L86";
	return s[n];
}

void num(int n, int *arr, int k) {
	if (k == n) {
		int i = 0;
		while (arr[i] == 0)
			i++;
		if (i == n)
			return;
		while (i < k)
			printf("%c", rev(arr[i++]));
		printf("\n");
		return;
	}
	for (int j = 0;j < 10;j++) {
		arr[k] = j;
		numbers(n, arr, k + 1);
	}
}
