#include "pch.h"
#include "header1.h"
int array_sum(int*arr, int i){ 
	if (i < 0)
		return 0;
	return arr[i] + array_sum(arr, i - 1);
}
