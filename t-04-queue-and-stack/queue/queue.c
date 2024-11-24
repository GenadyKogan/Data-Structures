#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Define the maximum size of the queue

// Structure for the queue
typedef struct Queue {
    int data[SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear + 1) % SIZE == queue->front;
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow: Cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;  // Set front to 0 if the queue is empty
    }

    queue->rear = (queue->rear + 1) % SIZE;  // Circular increment of rear
    queue->data[queue->rear] = value;  // Insert the value at the rear
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow: Cannot dequeue\n");
        return -1;  // Return -1 to indicate underflow
    }

    int value = queue->data[queue->front];  // Retrieve the front element

    if (queue->front == queue->rear) {
        // If only one element is in the queue, reset it to empty
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % SIZE;  // Circular increment of front
    }

    printf("Dequeued: %d\n", value);
    return value;
}

// Main function to demonstrate the queue operations
int main() {
    Queue queue;
    initializeQueue(&queue);

    // Enqueue some elements
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    // Try enqueueing to a full queue
    enqueue(&queue, 60);

    // Dequeue some elements
    dequeue(&queue);
    dequeue(&queue);

    // Enqueue after dequeue to test circular behavior
    enqueue(&queue, 60);
    enqueue(&queue, 70);

    // Try dequeueing all elements
    while (!isEmpty(&queue)) {
        dequeue(&queue);
    }

    // Try dequeueing from an empty queue
    dequeue(&queue);

    return 0;
}
