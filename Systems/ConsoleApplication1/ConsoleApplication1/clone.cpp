#include "pch.h"
#include "stdio.h"
#include "stdlib.h"

struct Node {
	int data;
	struct Node* next;
	struct Node* random;
};

struct Node* createNode(int k) {
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = k;
	n->next = NULL;
	n->random = NULL;
	return n;
}

struct Node* clone(struct Node* n) {
	struct Node* temp = n;
	while (n != NULL) {
		struct Node* n1 = createNode(n->data);
		n1->next = n->next;
		n->next = n1;
		n = n1->next;
	}
	struct Node* head = temp->next;
	struct Node* k = NULL;
	while (temp->next->next != NULL) {
		if(temp->random!=NULL)
			temp->next->random = temp->random->next;
		k = temp->next->next;
		temp->next->next = temp->next->next->next;
		temp = k;
	}
	return head;
}

int test_clone() {
	struct Node* n1 = createNode(1);
	struct Node* head = n1;
	struct Node* n2 = createNode(2);
	n1->next = n2;
	struct Node* n3 = createNode(3);
	n2->next = n3;
	struct Node* n4 = createNode(4);
	n3->next = n4;
	struct Node* n5 = createNode(5);
	n4->next = n5;
	n1->random = n1->next->next;
	n2->random = n2->next->next->next;
	n4->random = n1;

	while (head != NULL) {
		printf("%d ", head->data);
		if (head->random != NULL)
			printf("%d", head->random->data);
		printf("\n");
		head = head->next;
	}

	struct Node* temp = clone(n1);
	while (temp != NULL) {
		printf("%d ", temp->data);
		if (temp->random != NULL)
			printf("%d", temp->random->data);
		printf("\n");
		temp = temp->next;
	}
	return 0;
}

