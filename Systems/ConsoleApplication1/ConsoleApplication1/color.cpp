#include "pch.h"
#include "stdio.h"

//2 color sort using sum
void sort1(int* arr, int n) {
	int s = 0;
	for (int i = 0;i < n;i++)
		s += arr[i];
	int i = 0;
	while(i < n - s)
		arr[i++] = 0;
	while (i < n) {
		arr[i++] = 1;
	} 
}

//2 color sort using swap
void sort2(int* arr, int n) {
	int i = 0;
	int j = n - 1;
	while (i < j) {
		while (arr[i] == 0)
			i++;
		while (arr[j] == 1)
			j--;
		if (i < j) {
			arr[i++] = 0;
			arr[j--] = 1;
		}
	}
}

int main() {
	int arr[] = { 1,0,1,0 };
	sort1(arr);
	for (int i = 0;i < 4;i++)
		printf("%d ", arr[i]);
}
