#include "pch.h"
#include "header2.h"
struct node* reverse(struct node* n, int k) {
	struct node* current = n;
	struct node* next = NULL;
	struct node* prev = NULL;
	int j = 0;
	while (current!=NULL && j<k) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		j++;
	}
	if (j != k)
		return n;
	n->next = reverse(next, k);	
	return prev;
}

int test_knode()
{
	int k = 10;
	int n = 11;
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head->data = 0;
	head->next = NULL;
	struct node *prev = head;
	for (int i = 1;i <= n;i++) {
		struct node* t = (struct node*)malloc(sizeof(struct node));
		t->data = i;
		t->next = NULL;
		prev->next = t;
		prev = t;
	}
	head = reverse(head->next, k);
	for (int i = 0;i < n;i++) {
		printf("%d ", head->data);
		head = head->next;
	}
	return 0;
}








