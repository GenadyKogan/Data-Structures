#include <stdio.h>

// Function to check if a given array represents a max heap or not
int isMaxHeap(int arr[], int n, int i) {
    // If a node is a leaf node, it is a max heap
    if (i >= n / 2) {
        return 1;
    }

    // Check if the current node is less than its left child or right child
    if (arr[i] < arr[2 * i + 1] || (2 * i + 2 < n && arr[i] < arr[2 * i + 2])) {
        return 0; // Not a max heap
    }

    // Recursively check the left and right subtrees
    return isMaxHeap(arr, n, 2 * i + 1) && isMaxHeap(arr, n, 2 * i + 2);
}

int main() {

    int arr1[] = {88, 66, 77, 33, 44, 55, 75, 22, 30, 51}; // max heap
    int arr2[] = {88, 66, 77, 33, 44, 55, 75, 22, 30, 40}; // not max heap
    int n = sizeof(arr1) / sizeof(arr1[0]);

    if (isMaxHeap(arr1, n, 0)) {
        printf("The array is a max heap.\n");
    } else {
        printf("The array is not a max heap.\n");
    }

    return 0;
}
