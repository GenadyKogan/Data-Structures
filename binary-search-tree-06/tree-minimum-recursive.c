#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to find the minimum value in a binary search tree (recursive version)
struct TreeNode* tree_minimum_recursive(struct TreeNode* x) {
    // Base case: If x is NULL, the tree is empty
    if (x == NULL) {
        return NULL;
    }

    // Base case: If x has no left child, x is the minimum
    if (x->left == NULL) {
        return x;
    }

    // Recursive case: Traverse to the left child
    return tree_minimum_recursive(x->left);
}

// Example usage
int main() {
    // Create a simple binary search tree for testing
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->key = 5;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->key = 3;
    root->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->left->key = 2;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->key = 4;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->key = 8;
    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->left->key = 6;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right->key = 10;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    // Find the minimum value in the tree using the recursive algorithm
    struct TreeNode* min_node = tree_minimum_recursive(root);

    // Print the result
    if (min_node != NULL) {
        printf("The minimum value in the tree is: %d\n", min_node->key);
    } else {
        printf("The tree is empty.\n");
    }

    // Free allocated memory (recursive cleanup function is not provided)
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left->right);
    free(root->left->left);
    free(root->left);
    free(root);

    return 0;
}
