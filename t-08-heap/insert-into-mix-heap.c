#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform heapify-up operation after inserting a new value
void heapifyUp(int arr[], int index) {
    while (index > 0 && arr[(index - 1) / 2] > arr[index]) {
        swap(&arr[index], &arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Function to insert a new value into the min heap
void insertIntoMinHeap(int arr[], int *size, int value) {
    // Add the new value at the end of the heap
    arr[*size] = value;
    (*size)++;

    // Perform heapify-up to restore the min-heap property
    heapifyUp(arr, *size - 1);
}

// Function to print the elements of the heap
void printHeap(int arr[], int size) {
    printf("Heap: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int minHeap[100]; // Assuming a min heap with a maximum size of 100
    int heapSize = 0;

    // Example: Insert values into the min heap
    insertIntoMinHeap(minHeap, &heapSize, 10);
    printHeap(minHeap, heapSize);

    insertIntoMinHeap(minHeap, &heapSize, 5);
    printHeap(minHeap, heapSize);

    insertIntoMinHeap(minHeap, &heapSize, 20);
    printHeap(minHeap, heapSize);

    insertIntoMinHeap(minHeap, &heapSize, 15);
    printHeap(minHeap, heapSize);

    return 0;
}
