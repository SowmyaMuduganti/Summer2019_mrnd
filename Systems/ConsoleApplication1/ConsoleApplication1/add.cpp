#include "pch.h"
#include "header2.h"

struct node* createNode(int n) {
	struct node* Node = (struct node*)malloc(sizeof(struct node));
	Node->data = n;
	Node->next = NULL;
	return Node;
}
struct node* reverse(struct node* n) {
	struct node* prev = NULL;
	struct node* current = n;
	struct node* next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

struct node* add(struct node* n1, struct node* n2) {
	n1 = reverse(n1);
	n2 = reverse(n2);
	int k, c = 0;
	struct node* ans = createNode(0);
	struct node* temp = ans;
	while (n1 != NULL && n2 != NULL) {
		k = n1->data + n2->data + c;
		c = k / 10;
		ans->next = createNode(k % 10);
		ans = ans->next;
		n1 = n1->next;
		n2 = n2->next;
	}
	if (n1 != NULL) {
		ans->next = n1;
	}
	if (n2 != NULL) {
		ans->next = n2;
	}
	return reverse(temp->next);
}

int addll()
{
	int n1[] = {4,5};
	int n2[] = {1,2,3};
	struct node* h1 = createNode(0);
	struct node* h2 = createNode(0);
	struct node* t1 = h1;
	struct node* t2 = h2;
	for (int i = 0;i < 2;i++) {
		h1->next = createNode(n1[i]);
		h1 = h1->next;
	}
	for (int i = 0;i < 3;i++) {
		h2->next = createNode(n2[i]);
		h2 = h2->next;
	}
	struct node* ans = add(t1->next, t2->next);
	while (ans != NULL) {
		printf("%d ", ans->data);
		ans = ans->next;
	}
	return 0;
}
