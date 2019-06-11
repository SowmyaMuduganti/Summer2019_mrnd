#include "pch.h"
#include "header1.h"

void sort1(int* a, int n) {
	int i = 0;
	int j = n - 1;
	while (i < j) {
		while (i < n && a[i] == 0)
			i++;
		while (j >= 0 && a[j] == 1)
			j--;
		if (i < j) {
			a[i] = 0;
			a[j] = 1;
		}
	}
}

void sort(int* a, int n) {
	int b[] = { 0,0 };
	for (int i = 0;i < n;i++)
		b[a[i]] += 1;
	for (int i = 0;i < b[0];i++) {
		a[i] = 0;
	}
	for (int i = b[0];i < n;i++) {
		a[i] = 1;
	}
}

void twocolorsort() {
	int a[20];
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%d", &a[i]);
	//sort(a, n);
	sort1(a, n);
	for (int i = 0;i < n;i++) 
		printf("%d ", a[i]);
	printf("\n");
}
