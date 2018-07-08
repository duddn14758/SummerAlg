#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20000

int main() {
	FILE *fp;
	int *buffer1;
	int *buffer2;

	int count = 0;		//읽은 숫자 갯수
	int root;			//숫자갯수 루트
	int a_num;			//정규화된 배열의 갯수
	int min;			//min값이 들어갈 buffer
	int a_count = 0;	//buffer2에 넣을 인덱스포인터
	int head,tail;		//min찾기위해 입력할 숫자
	int size;			//file의 숫자갯수
	int result;			//결과값
	int i1 = 0;
	int i2=0;

	fp = fopen("data.txt", "rt");
	if (fp == NULL) {
		printf("파일 읽기 실패\n");
		return 1;
	}
	fscanf(fp, "%d", &size);
	buffer1 = (int*)malloc(sizeof(int)*size);

	while (feof(fp) == 0) {
		fscanf(fp, "%d", &buffer1[count++]);
	}
	root = (int)sqrt(count);
	a_num = count / root;
	
	buffer2 = (int*)malloc(sizeof(int)*root);

	
	printf("root : %d\n", root);
	printf("a_num : %d\n", a_num);

	if (count%root != 0) {
		a_num++;
	}
	min = buffer1[0];
	for (int i = 1; i < count; i++) {
		if (i%root == 0) {
			buffer2[a_count++] = min;
			min = buffer1[i];
		}
		else {
			if (min > buffer1[i]) {
				min = buffer1[i];
			}
		}
	}
	buffer2[a_count] = min;
	/*
	printf("원래배열 : ");
	for (int i = 0; i < count; i++) {
		printf("%d ", buffer1[i]);
	}
	printf("\n정규화된 배열 : ");
	for (int i = 0; i < a_num; i++) {
		printf("%d ", buffer2[i]);
	}
	printf("\n");
	*/
	
	while (1) {
		scanf("%d %d", &head, &tail);
	
		printf("head : %d, tail : %d\n", head, tail);
		if(head>tail)


		result = buffer1[head];
		while (head%root != 0&&head<tail) {
			if (result > buffer1[head]) {
				result = buffer1[head];
				i1 = head;
			}
			head++;
		}
	
		for (int i = (head / root); i < tail / root; i++) {
			if (result > buffer2[i]) {
				result = buffer2[i];
				i2 = i;
				i1 = 0;
			}
		}
		while (tail%root != 0&&head<tail) {
			if (result > buffer1[tail]) {
				result = buffer1[tail];
				i1 = tail;
				i2 = 0;
			}
			tail--;
		}	
		
		printf("buffer1에서 : %d, buffer2에서 : %d\n", i1,i2);
		printf("결과값 : %d\n", result);
	}
	

	return 0;
}