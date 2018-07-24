#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool recursion(int i, int j);
int move(int dir, int i, int j);

int N;
int **map;

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
		fscanf(fp,"%d",&N);
		map = (int**)malloc(sizeof(int*)*N);
		for (int i = 0; i < N; i++) {
			map[i] = (int *)malloc(sizeof(int)*N);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				fscanf(fp, "%d", &map[i][j]);
			}
		}
		if (recursion(0, 0))
			printf("true\n");
		else
			printf("false\n");
	}

	return 0;
}

bool recursion(int i, int j) {
	if (i == -1 || j == -1)
		return false;
	map[i][j] = 2;	
	
	//printf("현재위치 : %d %d\n",i,j);
	if (i == N - 1 && j == N - 1)
		return true;

	return recursion(move(0, i, j),j)|| recursion(i, move(1, i, j))
		|| recursion(move(2, i, j), j)||recursion(i, move(3, i, j));
}

int move(int dir, int i,int j) {
	switch (dir) {
	case 0:
		while (i<N-1&&map[i+1][j] != 1) {
			i++;
		}
		if (map[i][j] == 2)
			return -1;
		return i;
	case 1:
		while (j<N-1&& map[i][j+1] != 1) {
			j++;
		}
		if (map[i][j] == 2)
			return -1;
		return j;
	case 2:
		while (i>0&&map[i-1][j] != 1) {
			i--;
		}
		if (map[i][j] == 2)
			return -1;
		return i;
	case 3:
		while (i>0&&map[i][j-1] != 1) {
			j--;
		}
		if (map[i][j] == 2)
			return -1;
		return j;
	}
	return -1;
}