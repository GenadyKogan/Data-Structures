// Include header file
#include <stdio.h>
#include <stdlib.h>
/*
  C program for
  Find sum of even and odd nodes in a linked list
*/
// Linked list node
typedef struct LinkNode
{
	// Define useful field of LinkNode
	int data;
	struct LinkNode * next;
}LinkNode;

LinkNode * getLinkNode(int data)
{
	// Create dynamic memory of LinkNode
	LinkNode * ref = (LinkNode * ) malloc(sizeof(LinkNode));
	if (ref == NULL)
	{
		// Failed to create memory 
		return NULL;
	}
	ref->data = data;
	ref->next = NULL;
	return ref;
}
typedef struct SingleLL
{
	// Define useful field of SingleLL
	struct LinkNode * head;
	struct LinkNode * tail;
}SingleLL;

SingleLL * getSingleLL()
{
	// Create dynamic memory of SingleLL
	SingleLL * ref = (SingleLL * ) malloc(sizeof(SingleLL));
	if (ref == NULL)
	{
		// Failed to create memory 
		return NULL;
	}
	// Set initial value
	ref->head = NULL;
	ref->tail = NULL;
	return ref;
}
void insert(SingleLL * ref, int data)
{
	LinkNode * node = getLinkNode(data);
	if (ref->head == NULL)
	{
		// Add first node
		ref->head = node;
	}
	else
	{
		// Add node at the end position
		ref->tail->next = node;
	}
	// New last node
	ref->tail = node;
}
// Display linked list element
void display(SingleLL * ref)
{
	if (ref->head == NULL)
	{
		return;
	}
	LinkNode * temp = ref->head;
	// iterating linked list elements
	while (temp != NULL)
	{
		printf(" %d →", temp->data);
		// Visit to next node
		temp = temp->next;
	}
	printf(" NULL");
}
// Calculate Sum of all even and odd 
// nodes in a linked list.
void sumEvenOdd(SingleLL * ref)
{
	if (ref->head == NULL)
	{
		printf("\n Empty linked list");
		return;
	}
	// This is used to collect sum result
	int evenSum = 0;
	int oddSum = 0;
	// Get first node
	LinkNode * temp = ref->head;
	// Sum node values
	while (temp != NULL)
	{
		if (temp->data % 2 == 0)
		{
			// When node contains Even value
			evenSum += temp->data;
		}
		else
		{
			// When node contains Odd value
			oddSum += temp->data;
		}
		// Visit to next node
		temp = temp->next;
	}
	// Display node elements
	display(ref);
	// Display the value of calculated sum
	printf("\n Even Sum : %d", evenSum);
	printf("\n Odd Sum  : %d", oddSum);
}
int main()
{
	SingleLL * sll = getSingleLL();
	// Add linked list node
	//  2 → 5 → -1 → 8 → 10 → 4 → 9 → 7 → NULL
	insert(sll, 2);
	insert(sll, 5);
	insert(sll, -1);
	insert(sll, 8);
	insert(sll, 10);
	insert(sll, 4);
	insert(sll, 9);
	insert(sll, 7);
	// Test
	sumEvenOdd(sll);
}