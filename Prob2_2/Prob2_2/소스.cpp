#include <stdio.h>
#include <stdlib.h>

int floor(int start, int end);
int ceiling(int start, int end);

int K;
int *data;

int main() {
	int N;	
	int f, c;

	printf("입력받을 숫자 갯수 : ");
	scanf("%d", &N);
	data = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &data[i]);
	}
	printf("정수입력 : ");
	scanf("%d", &K);
	if (data[N - 1] < K) {
		f = data[N - 1];
		c = -1;
	}
	else if (data[0] > K) {
		f = -1;
		c = data[0];
	}
	else {
		f = data[floor(0, N - 1)];
		c = data[ceiling(0, N - 1)];
	}
	
	printf("floor : %d\n", f);
	printf("ceiling : %d\n", c);
	return 0;
}

int floor(int start, int end) {
	if (data[end] < K)
		return end;

	if (data[start] > K)
		return -1;

	if (end-start == 1)
		return start;

	if (data[(start + end) / 2] < K) {
		return floor((start + end) / 2 , end);
	}
	else if (data[(start + end) / 2] > K) {
		return floor(start, (start + end) / 2);
	}
}

int ceiling(int start, int end) {
	if (data[end] < K)
		return -1;

	if (data[start] > K)
		return start;
	if (end - start == 1)
		return end;

	if (data[(start + end) / 2] < K) {
		return ceiling((start + end) / 2, end);
	}
	else if (data[(start + end) / 2] > K) {
		return ceiling(start, (start + end) / 2);
	}
}