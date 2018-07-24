#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int K, N;
int **map;
int recursion(int i, int j, int count);

int main() {
	FILE *fp;
	int T;
	fp = fopen("data.txt", "rt");
	if (fp == NULL) {
		printf("파일 읽기 실패\n");
		return 1;
	}
	fscanf(fp, "%d", &T);
	while (feof(fp) == 0) {
		fscanf(fp, "%d", &N);
		map = (int**)malloc(sizeof(int*)*N);
		for (int i = 0; i < N; i++) {
			map[i] = (int *)malloc(sizeof(int)*N);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				fscanf(fp, "%d", &map[i][j]);
				//printf("%d ", map[i][j]);
			}
			//printf("\n");
		}
		fscanf(fp, "%d", &K);
		printf("%d\n", recursion(0, 0, 0));

		free(map[0]);
		free(map);
	}	

	return 0;
}

int recursion(int i, int j, int count) {
	map[i][j] = 2;
	int way = 0;
	if (i == N - 1 && j == N - 1 && count <= K) {
		map[i][j] = 0;
		return 1;
	}

	if (i < N - 1 && map[i+1][j]==0) {		
		way += recursion(i+1, j, count + 1);
	}
	if (j < N - 1 && map[i][j+1]==0) {
		way += recursion(i, j+1, count + 1);
	}
	if (i > 0 && map[i-1][j]==0) {
		way += recursion(i-1, j, count + 1);
	}
	if (j > 0 && map[i][j-1]==0) {
		way += recursion(i, j-1, count + 1);
	}
	map[i][j] = 0;

	return way;
}
