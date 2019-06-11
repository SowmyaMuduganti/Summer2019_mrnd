#include "pch.h"
#include "header1.h"
#include "string.h"

//recursive
void traverse2(int arr[][100], int m, int n, int a, int b) {
	if (a < m && b < n) {
		for (int i = a; i < n; i++) {
			printf("%d ", arr[a][i]);
		}
		a++;

		for (int i = a; i < m; i++) {
			printf("%d ", arr[i][n - 1]);
		}
		n--;

		for (int i = n - 1; i >= b; i--) {
			printf("%d ", arr[m - 1][i]);
		}
		m--;

		for (int i = m - 1; i >= a; i--) {
			printf("%d ", arr[i][b]);
		}
		b++;

		traverse2(arr, m - 1, n - 1, a + 1, b + 1);
	}
}


//iterative
void traverse1(int arr[][100],int m,int n) {
	int a = 0, b = 0;
	while (a < m && b < n) {
		for (int i = a; i < n; i++) {
			printf("%d ", arr[a][i]);
		}
		a++;
		
		for (int i = a; i < m; i++) {
			printf("%d ", arr[i][n - 1]);
		}
		n--;

		for (int i = n - 1; i >= b; i--) {
			printf("%d ", arr[m - 1][i]);
		}
		m--;

		for (int i = m - 1; i >= a; i--) {
			printf("%d ", arr[i][b]);
		}
		b++;
	}
}

int test_spiraltraversal() {
	int m, n;
	scanf("%d %d", &m, &n);
	int matrix[100][100];
	printf("matrix elements:\n");
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%d", &matrix[i][j]);
	traverse1(matrix, m, n);
	//traverse2(matrix, m, n, 0, 0);
	return 0;
}

