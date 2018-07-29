#include <stdlib.h>
#include <stdio.h>
#include "method.h"


int *MakeArry(int N) {
	int *arr;
	arr = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
		arr[i] = rand() % N;
	return arr;
}

int *MakeReverse(int N) {
	int *arr;
	arr = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
		arr[i] = N - i;
	return arr;
}

int *Bubble(int *arr, int N) {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	return arr;
}

int *Selection(int *arr, int N) {
	int M_index = 0;
	while (N > 0) {
		M_index = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] > arr[M_index])
				M_index = i;
		}
		swap(arr[--N], arr[M_index]);
	}
	return arr;
}

int *Insertion(int *arr, int N) {
	int tmp;
	for (int i = 1; i < N; i++) {
		if (arr[i - 1] > arr[i]) {
			tmp = arr[i];
			int j = i;
			while (--j >= 0) {
				if (arr[j] > tmp)
					swap(arr[j], arr[j + 1]);
			}
		}
	}

	return arr;
}

int *Merge(int *arr, int p, int r) {
	if (p < r) {
		
		int q = (p + r) / 2;
		Merge(arr, p, q);
		Merge(arr, q + 1, r);

		return merging(arr, p, q, r);
	}
	return arr;
}

int* merging(int *arr, int p, int q, int r) {
	int origin = p;
	int i = 0, j = 0;
	int* arr1 = (int*)malloc(sizeof(int)*(q - p + 1));
	int *arr2 = (int*)malloc(sizeof(int)*(r - q));
	arr1 = copying(arr, arr1, p, q);
	arr2 = copying(arr, arr2, q + 1, r);	

	while (i<=q-p&&j<= r-q-1) {
		if (arr1[i] < arr2[j]) {
			//printf("배열복사! -- %d\n", arr1[i]);

			arr[origin++] = arr1[i++];
			//printf("i : %d, q : %d\n", i, q);
			
		}
		else if (arr1[i] >= arr2[j]) {
			//printf("배열복사! -- %d\n", arr2[j]);
			arr[origin++] = arr2[j++];
			//printf("j : %d, r : %d\n", j, r);

		}
	}
	while (i <= q-p) {
		//printf("주르륵배열복사! -- %d\n", arr1[i]);

		arr[origin++] = arr1[i++];
	}
	while (j <= r-q-1) {
		//printf("주르륵배열복사! -- %d\n", arr2[j]);

		arr[origin++] = arr2[j++];
	}
	free(arr1);
	free(arr2);
	return arr;
}

int *copyarr(int *arr, int h, int t) {
	int *cpyarr;
	int point = 0;
	cpyarr = (int*)malloc(sizeof(int)*(h - t + 1));
	printf("%d부터 %d까지 복사된배열\n", h,t);
	while (h <= t) {
		printf("%d\n", arr[h]);
		cpyarr[point++] = arr[h++];
	}
	return cpyarr;
}

int *copying(int *arr, int *cpyarr, int h, int t) {
	int point = 0;
	//printf("%d부터 %d까지 복사된배열\n", h, t);
	while (h <= t) {
		//printf("%d\n", arr[h]);
		cpyarr[point++] = arr[h++];
	}
	return cpyarr;

}



void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

