#include <stdio.h>

// Function to calculate the sum of even numbers and remove them from the queue
void sum_of_even_numbers(int queue[], int size, int *total_sum, int *new_size) {
    *total_sum = 0;
    int even_numbers[size];
    int even_count = 0;

    for (int i = 0; i < size; i++) {
        if (queue[i] % 2 == 0) {
            *total_sum += queue[i];
            even_numbers[even_count++] = queue[i];
        }
    }

    // Remove even numbers from the queue
    for (int i = 0; i < even_count; i++) {
        for (int j = 0; j < size; j++) {
            if (queue[j] == even_numbers[i]) {
                // Shift elements to fill the gap
                for (int k = j; k < size - 1; k++) {
                    queue[k] = queue[k + 1];
                }
                size--;  // Adjust the size after removal
                j--;     // Check the same index again, as elements shifted
            }
        }
    }

    *new_size = size;
}

int main() {
    int number_queue[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(number_queue) / sizeof(number_queue[0]);

    int sum, new_size;
    sum_of_even_numbers(number_queue, size, &sum, &new_size);

    printf("Sum of even numbers: %d\n", sum);
    printf("Queue after removing even numbers: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", number_queue[i]);
    }

    return 0;
}
