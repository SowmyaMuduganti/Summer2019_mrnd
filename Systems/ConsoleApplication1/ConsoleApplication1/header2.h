#pragma once
#ifndef HEADER2_H    
#define HEADER2_H
#include "pch.h"
#include "stdio.h"
#include "stdlib.h"

struct node {
	int data;
	struct node* next;
};

int test_loop();
int addll();
int test_knode();
int test_clone();

#endif
