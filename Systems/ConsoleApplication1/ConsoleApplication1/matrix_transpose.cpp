#include "pch.h"
#include "header1.h"
void transpose(int matrix[][100], int r, int c, int res[][100]) {
	for (int i = 0;i < c;i++) {
		for (int j = 0;j < r;j++)
			res[i][j] = matrix[j][i];
	}
}

int test_transpose() {
	int m, n;
	scanf("%d %d", &m, &n);
	int matrix[100][100];
	printf("matrix elements:\n");
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf_s("%d", &matrix[i][j]);
	int res[100][100];
	transpose(matrix, m, n, res);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}
	return 0;
}


