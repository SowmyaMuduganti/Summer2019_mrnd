#include "pch.h"
#include "header2.h"

struct node* createNode(int n) {
	struct node* Node = (struct node*)malloc(sizeof(struct node));
	Node->data = n;
	Node->next = NULL;
	return Node;
}

int findLoop(struct node* n) {
	struct node* slow = n->next;
	struct  node* fast = n->next->next;
	while (fast!=NULL && fast->next!=NULL) {
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}
	if (slow == fast) {
		slow = n;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		printf("Meeting point: %d\n", slow->data);
		return 1;
	}
	return 0;
}

int test_loop() {
	struct node* n1 = createNode(1);
	struct node* n2 = createNode(2);
	struct node* n3 = createNode(3);
	struct node* n4 = createNode(4);
	struct node* n5 = createNode(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n5;
	printf("%d\n",findLoop(n1));
	return 0;
}
