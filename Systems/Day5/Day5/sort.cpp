#include "sort.h"

int partition(int* arr, int low, int high) {
	int i = low-1, pivot = arr[high],temp;
	for (int j = low;j < high;j++) {
		if (arr[j] <= pivot) {
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return(i + 1);
}

void quickSort(int* arr,int low,int high) {
	if (low < high) {
		int p = partition(arr, low, high);
		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1,high);
	}
	return;
}

void sortFile(char* fileName) {
	FILE* fp1 = fopen("output.txt", "a+");
	int* arr = (int*)malloc(sizeof(int) * 5);
	FILE* fp = fopen(fileName, "r+");
	int t;
	int i = 0;
	while (fscanf(fp, "%d", &t)!=EOF) {
		arr[i++] = t;
	}
	quickSort(arr,0,i-1);
	fseek(fp, 0, SEEK_SET);
	for (int j = 0;j < i;j++) {
		fprintf(fp1, "%d\n", arr[j]);
	}
	fclose(fp1);
}

void sort(char* fileName, int range, int n){
	FILE* fptr = fopen(fileName, "r");
	int t;
	char fname[10];
	
	char* file = (char*)malloc(10);
	while (fscanf(fptr, "%d", &t)!=EOF) {
		_itoa(t / n, fname, 10);
		file = strcat(fname, ".txt");
		FILE* fp = fopen(file, "a+");
		fprintf(fp, "%d\n", t);
		fclose(fp);
	}
	for (int i = 0;i < (range / n);i++) {
		_itoa(i, fname, 10);
		file = strcat(fname, ".txt");
		FILE* fp = fopen(file, "r");
		if (fp != NULL) {
			fclose(fp);
			sortFile(file);
		}
	}
	fclose(fptr);
}

int file_sorting() {
	int range = 100;
	char fileName[20] = "input.txt";
	int n = 5;
	sort(fileName, range, n);
	return 0;
}

