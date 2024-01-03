#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to search for a value in a binary search tree
bool searchBST(struct TreeNode* root, int target) {
    while (root != NULL) {
        if (root->value == target) {
            return true;  // Value found
        } else if (root->value < target) {
            root = root->right;  // Move to the right subtree
        } else {
            root = root->left;  // Move to the left subtree
        }
    }
    return false;  // Value not found
}

// Example usage
int main() {
    // Creating a binary search tree
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->value = 5;
    root->left = malloc(sizeof(struct TreeNode));
    root->left->value = 3;
    root->left->left = malloc(sizeof(struct TreeNode));
    root->left->left->value = 1;
    root->left->right = malloc(sizeof(struct TreeNode));
    root->left->right->value = 4;
    root->right = malloc(sizeof(struct TreeNode));
    root->right->value = 8;
    root->right->left = malloc(sizeof(struct TreeNode));
    root->right->left->value = 7;
    root->right->right = malloc(sizeof(struct TreeNode));
    root->right->right->value = 9;

    // Searching for a value in the BST
    int targetValue = 1;
    bool result = searchBST(root, targetValue);

    // Printing the result
    printf(result ? "Value found!\n" : "Value not found!\n");

    // Freeing allocated memory (not shown in the original code)
     free(root->right->right);
     free(root->right->left);
     free(root->right);
     free(root->left->right);
     free(root->left->left);
     free(root->left);
     free(root);

    return 0;
}
