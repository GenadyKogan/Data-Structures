#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}

int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b)? a : b;
}

int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node* sortedArrayToAVL(int arr[], int start, int end) {
    if (start > end)
        return NULL;


    int mid = (start + end)/2;
    struct Node *root = newNode(arr[mid]);

    root->left = sortedArrayToAVL(arr, start, mid-1);
    root->right = sortedArrayToAVL(arr, mid+1, end);

    root->height = 1 + max(height(root->left), height(root->right));

    return root;
}


void printPreOrder(struct Node* root) {
    if(root != NULL) {
        printf("%d ", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct Node *root = sortedArrayToAVL(arr, 0, n-1);

    printf("Preorder traversal of constructed AVL tree is: \n");
    printPreOrder(root);

    return 0;
}
