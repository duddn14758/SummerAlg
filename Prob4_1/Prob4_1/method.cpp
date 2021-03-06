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
			arr[origin++] = arr1[i++];			
		}
		else if (arr1[i] >= arr2[j]) {
			arr[origin++] = arr2[j++];
		}
	}
	while (i <= q-p) {
		arr[origin++] = arr1[i++];
	}
	while (j <= r-q-1) {
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
	while (h <= t) {
		cpyarr[point++] = arr[h++];
	}
	return cpyarr;

}

int *Quick1(int *arr, int p, int r) {
	if (p < r) {
		int q = partition(arr, p, r);
		Quick1(arr, p, q-1);
		Quick1(arr, q + 1, r);
		return arr;
	}	
	return arr;
}

int partition(int *arr, int p, int r) {
	int pivot = arr[r];
	int i = r, j = r;
	while (--j >= p) {
		if (arr[j] > pivot) {
			int tmp = arr[j];
			for (int k = j; k < i; k++) {
				arr[k] = arr[k + 1];
			}
			arr[i--] = tmp;
		}
	}
	return i;
}

int *Quick2(int *arr, int p, int r) {	
	if (p < r) {
		partition2(arr, p, r);
		int q = partition(arr, p, r-1);
		Quick2(arr, p, q-1);
		Quick2(arr, q + 1, r);
		return arr;
	}
	return arr;
}

void partition2(int *arr, int p, int r) {
	int q = (p + r) / 2;
	if (arr[p] > arr[q]) {
		swap(arr[p], arr[q]);
	}
	if (arr[q] > arr[r]) {
		swap(arr[q], arr[r]);
	}
	if (arr[p] > arr[r]) {
		swap(arr[q], arr[r]);
	}	
	swap(arr[q], arr[r-1]);
}

int *Quick3(int *arr, int p, int r) {
	if (p < r) {
		partition3(arr, p, r);
		int q = partition(arr, p, r);
		Quick3(arr, p, q - 1);
		Quick3(arr, q + 1, r);
		return arr;
	}
	return arr;
}

void partition3(int *arr, int p, int r) {
	int random = rand()%(r-p);
	swap(arr[p + random], arr[r]);
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

