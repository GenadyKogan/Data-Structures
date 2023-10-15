//
// Created by rgkog on 9/27/2023.
//
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void task1(int);
void task2(int);
void task3(int);
void task4(int);
// task6
int countSingles(int A[], int length);
void task6(int);
void task7(int);
void task8(int);
void task9(int n);
int task11(int arr[], int n, int* max1, int* max2, int* comparisons);
// task 11: tree solution
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(int data);
struct TreeNode* insert(struct TreeNode* root, int data);
void findTwoLargest(struct TreeNode* root, int* max1, int* max2);


// 19.02.2018
void task12(int);

//=========================================
//=========================================
int main(void){
    int n=16;
    int A[] = {1, 2, 3, 2, 4, 3, 5};
    int length = sizeof(A) / sizeof(A[0]);
//    task1(n);
//    task2(n);
//    task3(n);
//    task4(n);
//    countSingles(A, length);
//    task6(n);
//    task7(n);
//    task8(n);
    task9(n);

//=========================================
// task 11.1 using array
//=========================================
    /*printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array does not have two largest elements.\n");
        return 1; // Exit with an error code
    }

    int arr[n]; // Declare an array of size n
    printf("Enter %d elements:\n", n);

    // Read elements into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max1, max2, comparisons;

    //task10(arr, n, &max1, &max2, &comparisons);

    printf("First largest element: %d\n", max1);
    printf("Second largest element: %d\n", max2);
    printf("Number of comparisons: %d\n", comparisons);*/

//=========================================
// task 11.2 using tree
//=========================================
//    printf("Enter the number of elements: ");
//    scanf("%d", &n);
//
//    if (n < 2) {
//        printf("Array does not have two largest elements.\n");
//        return 1; // Exit with an error code
//    }
//
//    int arr[n]; // Declare an array of size n
//    printf("Enter %d elements:\n", n);
//
//    // Read elements into the array
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    // Build a BST from the array elements
//    struct TreeNode* root = NULL;
//    for (int i = 0; i < n; i++) {
//        root = insert(root, arr[i]);
//    }
//
//    int max1 = -1, max2 = -1;
//
//    // Find the largest and second largest elements in the BST
//    findTwoLargest(root, &max1, &max2);
//
//    // Print the two largest elements
//    printf("First largest element: %d\n", max1);
//    printf("Second largest element: %d\n", max2);

    task12(n);
    return 0;
}
//=========================================
//=========================================
void task1(int n){
    int sum=0,i=1;
    while(i<=n){
        sum=sum+i;
        i=i+1;
    }
}
//=========================================
void task2(int n){
    int sum=0,i=1;
    for(int i=1;i<=n;i++){
       sum=sum+i;
    }
}
//=========================================
void task3(int n){
    int sum=0,prod=1;
    for(int i=1;i<=n;i++){
        sum=sum+1;
        prod=prod*i;
    }
}
//========================================
void task4(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++) {
            sum = sum + i * j;
        }
    }
}

//=========================================

int countSingles(int A[], int length) {
    int singles = 0;
    for (int i = 0; i < length; i++) {
        int occurs = 0;
        for (int j = 0; j < length; j++) {
            if (A[i] == A[j]) {
                occurs++;
            }
        }
        if (occurs == 1) {
            singles++;
        }
    }
    return singles;
}
//=========================================

void task6(int n){
    int k = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            k = k + 1;
        }
    }

    
}

//=========================================

void task7(int n){
    int k = 0;
    int i = 1;
    int q = 1;
    int r = 4;
    while (i <= n) {
        int j = 0;
        while (j < q) {
            k = k + 1;
            j = j + 1;
        }
        printf("k = %d\n", k);
        q = q * r;
        i = i + 1;
    }
}

//=========================================
void task8(int n){
    int k = 0;
    int i = 1;

    while (i < n) {
        k = k + 1;
        i = i * 2;

    }
    printf("k = %d\n", k);
}

//=========================================
void task9(int n){

    for (int i = 1; i <= n; i++) {
        int k = 1;
        int j=0;
        while (k < i) {
            k = k * 2;
            j=j+1;
            printf("inner loop; j = %d\n",j);
        }
        // At this point, the value of k will be the largest power of 2 less than or equal to i.
        printf("i = %d, k = %d\n", i, k);
    }
    /*https://stackoverflow.com/questions/2095395/is-logn-%ce%98n-logn*/
}

//=========================================
//=========================================
// task 11.1 using array
//=========================================
int task11(int arr[], int n, int* max1, int* max2, int* comparisons){
    if (n < 2) {
        printf("Array does not have two largest elements.\n");
        return;
    }

    *comparisons = 0;

    if (arr[0] > arr[1]) {
        *max1 = arr[0];
        *max2 = arr[1];
    } else {
        *max1 = arr[1];
        *max2 = arr[0];
    }

    for (int i = 2; i < n; i++) {
        (*comparisons)++;
        if (arr[i] > *max1) {
            *max2 = *max1;
            *max1 = arr[i];
        } else if (arr[i] > *max2) {
            *max2 = arr[i];
        }
    }

}
//=========================================
// task 11.2 using tree
//=========================================
// To find the two largest numbers in an array using a binary search tree (BST), you can follow these steps:
// 1. Build a BST from the elements of the array.
// 2. Traverse the BST to find the largest and second largest elements.

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the largest and second largest elements in the BST
void findTwoLargest(struct TreeNode* root, int* max1, int* max2) {
    if (root == NULL) {
        return;
    }

    findTwoLargest(root->right, max1, max2);

    if (root->data > *max1) {
        *max2 = *max1;
        *max1 = root->data;
    } else if (root->data > *max2 && root->data != *max1) {
        *max2 = root->data;
    }

    findTwoLargest(root->left, max1, max2);
}

//=========================================

void task12(int n){
    int i = 1;
    int k = 0;
      while (i <= n) {
        for (int j = i; j <= n * n; j++) {
            k = k + 1;
        }
        i = i * 2;
    }
}