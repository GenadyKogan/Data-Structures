#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Define the maximum size of the stack

// Structure for the stack
typedef struct Stack {
    int data[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initializeStack(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
    printf("Pushed %d onto the stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;  // Return an error value
    }
    int value = stack->data[stack->top--];
    return value;
}

// Main function to demonstrate the stack operations
int main() {
    Stack stack;
    initializeStack(&stack);

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Pop elements from the stack
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));

    // Check if the stack is empty
    if (isEmpty(&stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    // Pop the remaining element
    printf("Popped: %d\n", pop(&stack));

    // Try popping from an empty stack
    printf("Popped: %d\n", pop(&stack));

    return 0;
}
