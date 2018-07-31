#include <stdio.h>
#include <time.h>
#include "method.h"
#include "setting.h"
#include <stdlib.h>

int *arr1 = NULL, *arr2 = NULL, *arr3 = NULL, *arr4 = NULL, *arr5 = NULL, *arr6 = NULL;

void C_Bubble() {		//Sort 6개의 시간 전부를 구한다	
	printf("BubbleSort\t");

	Calculate(arr1, 1000, 1, 0);		//bubble의 1번 시간
	Calculate(arr2, 1000, 1, 1);		//bubble의 2번 시간
	Calculate(arr3, 10000, 1, 0);
	Calculate(arr4, 10000, 1, 1);
	Calculate(arr5, 100000, 1, 0);
	Calculate(arr6, 100000, 1, 1);
	printf("\n");
}

void C_Selection() {
	printf("SelectionSort\t");

	Calculate(arr1, 1000, 2, 0);
	Calculate(arr2, 1000, 2, 1);
	Calculate(arr3, 10000, 2, 0);
	Calculate(arr4, 10000, 2, 1);
	Calculate(arr5, 100000, 2, 0);
	Calculate(arr6, 100000, 2, 1);
	printf("\n");

}

void C_Insertion() {
	printf("InsertionSort\t");

	Calculate(arr1, 1000, 3, 0);
	Calculate(arr2, 1000, 3, 1);
	Calculate(arr3, 10000, 3, 0);
	Calculate(arr4, 10000, 3, 1);
	Calculate(arr5, 100000, 3, 0);
	Calculate(arr6, 100000, 3, 1);
	printf("\n");

}

void C_Merge() {
	printf("MergeSort\t");
	Calculate(arr1, 1000, 4, 0);
	Calculate(arr2, 1000, 4, 1);
	Calculate(arr3, 10000, 4, 0);
	Calculate(arr4, 10000, 4, 1);
	Calculate(arr5, 100000, 4, 0);
	Calculate(arr6, 100000, 4, 1);
	printf("\n");

}

void C_Quick1() {
	printf("QuickSort1\t");
	Calculate(arr1, 1000, 5, 0);
	Calculate(arr2, 1000, 5, 1);
	Calculate(arr3, 10000, 5, 0);
	Calculate(arr4, 10000, 5, 1);
	Calculate(arr5, 100000, 5, 0);
	Calculate(arr6, 100000, 5, 1);	
	printf("\n");
}

void C_Quick2() {
	printf("QuickSort2\t");
	arr1 = MakeReverse(1000);
	arr1 = Quick2(arr1, 0, 999);
	//Print(arr1, 1000);
}


void Calculate(int *arr, int N, int command, int type) {		//command에 따라 다른 배열 정렬시간 계산
	clock_t startTime, endTime;
	double nProcessExcuteTime;
	if (type == 0) {				// reverse일지 랜덤일지 배열 설정
		arr = MakeArry(N);
	}
	else {
		arr = MakeReverse(N);
	}
	startTime = clock();
	switch (command) {				// command : sorting할 알고리즘의 종류
	case 1:
		arr = Bubble(arr, N);
		break;
	case 2:
		arr = Selection(arr, N);
		break;
	case 3:
		arr = Insertion(arr, N);
		break;
	case 4:
		arr = Merge(arr, 0, N - 1);
		break;
	case 5:
		arr = Quick1(arr, 0, N - 1);
		//Print(arr,N);
		break;
	}

	endTime = clock();
	nProcessExcuteTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
	printf("%f\t", nProcessExcuteTime);
	free(arr);
}

void Print(int *arr, int N) {
	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
}

void PrintColumn() {
	printf("\t\tRandom1000\tReverse1000\tRandom10000\tReverse10000\tRandom100000\tReverse100000\n");
}