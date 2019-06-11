#include "pch.h"
#include "header1.h"

void sort(int* a, int n) {
	int b[] = { 0,0,0 };
	for (int i = 0;i < n;i++)
		b[a[i]] += 1;
	int i = 0;
	while(i < b[0]) {
		a[i] = 0;
		i++;
	}
	while(i<b[1]) {
		a[i] = 1;
		i++;
	}
	while (i < b[2]) {
		a[i] = 2;
		i++;
	}
}

void threecolorsort() {
	int a[20];
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%d", &a[i]);
	sort(a, n);
	for (int i = 0;i < n;i++)
		printf("%d ", a[i]);
	printf("\n");
}