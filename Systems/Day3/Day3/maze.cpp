#include "stdio.h"

bool possible(int r, int c, int m[][5], int visited[][5]) {
	if ((r < 5 && r>=0) && (c<5 && c>=0))
		return(visited[r][c] != 1 && m[r][c] == 1);
	return false;
}

int solve(int m[][5], int x1, int y1, int x2, int y2, int visited[][5], int solution[][5]) {
	if (x1 == x2 && y1 == y2)
		return 1;
	visited[x1][y1] = 1;
	//printf("%d %d\n", x1, y1);
	if (possible(x1, y1 + 1, m, visited) && solve(m, x1, y1 + 1, x2, y2, visited, solution)) {
		solution[x1][y1 + 1] = 1;
		return 1;
	}
	if (possible(x1, y1 - 1, m, visited) && solve(m, x1, y1 - 1, x2, y2, visited, solution)) {
		solution[x1][y1 - 1] = 1;
		return 1;
	}
	if (possible(x1 + 1, y1, m, visited) && solve(m, x1 + 1, y1, x2, y2, visited, solution)) {
		solution[x1 + 1][y1] = 1;
		return 1;
	}
	if (possible(x1 - 1, y1, m, visited) && solve(m, x1 - 1, y1, x2, y2, visited, solution)) {
		solution[x1 - 1][y1 + 1] = 1;
		return 1;
	}
	visited[x1][y1] = 0;
	return 0;
}


int main() {
	int m[5][5] = { {1,1,0,1,1},{1,0,1,1,1},{1,1,1,0,1},{1,0,1,0,1},{1,1,1,1,1} };
	int visited[5][5] = { 0 };
	int solution[5][5] = { 0 };
	int n = solve(m, 0, 0, 4, 4, visited,solution);
	solution[0][0] = 1;
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++)
			printf("%d ", solution[i][j]);
		printf("\n");
	}
	return 0;
}
