//
// Created by rgkog on 12/10/2023.
//


#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Define the LinkedList structure
struct LinkedList {
    struct Node* head;
};

// Bubble Sort function for a linked list
struct LinkedList* bubbleSortLinkedList(struct LinkedList* list) {
    if (list->head == NULL || list->head->next == NULL) {
        return list;  // Empty list or list with one element is already sorted
    }

    int sorted;
    struct Node* current;
//    struct Node* previous = NULL;

    do {
        sorted = 1;  // Assume the list is sorted

        current = list->head;
        //previous = NULL;

        while (current->next != NULL) {
            if (current->data > current->next->data) {
                // Swap the data of current and next nodes
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                sorted = 0;  // Mark that a swap occurred
            }

            // Move to the next nodes
            //previous = current;
            current = current->next;
        }
    } while (!sorted);

    return list;
}

// Function to print the linked list
void printList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to create a new node with a given value
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        // Memory allocation error
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct LinkedList* list, int value) {
    struct Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    struct Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to free the memory of the linked list
void freeList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;  // Set head to NULL after freeing all nodes
}

int main() {
    // Create a sample linked list
    struct LinkedList myList;
    myList.head = NULL;

    insertEnd(&myList, 5);
    insertEnd(&myList, 10);
    insertEnd(&myList, 2);
    insertEnd(&myList, 9);
    insertEnd(&myList, 1);
    insertEnd(&myList, 5);

    // Print the original list
    printf("Original List: ");
    printList(&myList);

    // Apply Bubble Sort
    bubbleSortLinkedList(&myList);

    // Print the sorted list
    printf("Sorted List: ");
    printList(&myList);

    // Free the memory of the linked list
    freeList(&myList);

    return 0;
}
