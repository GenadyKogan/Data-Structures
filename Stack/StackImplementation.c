#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;               // integer data
    struct Node* next;      // pointer to the next node
};
 
// Utility function to add an element `x` to the stack
void push(struct Node **top, int x)        // insert at the beginning
{
    // allocate a new node in a heap
    struct Node* node = NULL;
    node = (struct Node*)malloc(sizeof(struct Node));
 
    // check if stack (heap) is full. Then inserting an element would
    // lead to stack overflow
    if (!node)
    {
        printf("\nHeap Overflow");
        exit(1);
    }
 
    printf("Inserting %d\n", x);
 
    // set data in the allocated node
    node->data = x;
 
    // set the `.next` pointer of the new node to point to the current
    // top node of the list
    node->next = *top;
 
    // update top pointer
    *top = node;
}
 
// Utility function to check if the stack is empty or not
int isEmpty(struct Node* top) {
    return top == NULL;
}
 
// Utility function to return the top element of the stack
int peek(struct Node *top)
{
    // check for an empty stack
    if (!isEmpty(top)) {
        return top->data;
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 
// Utility function to pop a top element from the stack
void pop(struct Node** top)        // remove at the beginning
{
    struct Node *node;
 
    // check for stack underflow
    if (*top == NULL)
    {
        printf("\nStack Underflow");
        exit(1);
    }
 
    printf("Removing %d\n", peek(*top));
 
    node = *top;
 
    // update the top pointer to point to the next node
    *top = (*top)->next;
 
    // free allocated memory
    free(node);
}
 
int main(void)
{
    struct Node* top = NULL;
 
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
 
    printf("The top element is %d\n", peek(top));
 
    pop(&top);
    pop(&top);
    pop(&top);
 
    if (isEmpty(top)) {
        printf("The stack is empty");
    }
    else {
        printf("The stack is not empty");
    }
 
    return 0;
}
