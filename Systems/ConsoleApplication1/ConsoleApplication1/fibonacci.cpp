#include "pch.h"
#include "header1.h"
long fib(int n, int* arr){
	if (n == 0 || n == 1)
		return n;
	if (arr[n] == 0)
		arr[n] = fib(n - 1, arr) + fib(n - 2, arr);
	return(arr[n]);
}

int test_fib() {
	int arr[10] = { 0 };
	int n;
	scanf("%d", &n);
	printf("%ld", fib(n, arr));
	for (int i = 0;i <= n;i++)
		printf("%d ", arr[i]);
	return 0;
}

