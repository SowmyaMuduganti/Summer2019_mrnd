#include "pch.h"
#include "header1.h"
int stairs(int n) {
	if (n == 0)
		return 0;
	int s = 0;
	for (int i = n;i > 1;i--) {
		s += stairs(i - 1)+ n - i + 1;
	}
	return s;
}
