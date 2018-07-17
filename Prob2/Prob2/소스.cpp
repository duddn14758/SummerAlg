#include <stdio.h>
#include <stdlib.h>

int K;
int *data;

int recursive(int start, int end);

int main() {
	int N;
	int start = 0, end;	

	printf("입렵받을 숫자 갯수 : ");
	scanf("%d", &N);
	end = N - 1;

	data = (int*)malloc(sizeof(int)*N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &data[i]);
	}
	printf("합계 입력 : ");
	scanf("%d", &K);	

	printf("결과 : %d개\n", recursive(start,end));

	return 0;
}

int recursive(int start, int end) {
	if (start >= end)
		return 0;
	if (data[start] + data[end] > K) {
		return recursive(start, end - 1);
	}else if(data[start]+data[end]<K){
		return recursive(start + 1, end);
	}
	else
		return 1+recursive(start+1,end-1);
}

