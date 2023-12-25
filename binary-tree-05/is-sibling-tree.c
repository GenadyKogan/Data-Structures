#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a binary tree
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to check if a tree is a sibling tree
bool isSiblingTree(struct TreeNode* root) {
    // Base case: an empty tree is a sibling tree
    if (root == NULL) {
        return true;
    }

    // Base case: a leaf node is a sibling tree
    if (root->left == NULL && root->right == NULL) {
        return true;
    }

    // Check if the right child's data follows the left child's data
    if ((root->left != NULL && root->right != NULL) &&
        (root->left->data == root->right->data)) {
        // Recursively check for sibling trees in the left and right subtrees
        return isSiblingTree(root->left) && isSiblingTree(root->right);
    }

    // If the right child's data does not follow the left child's data, return false
    return false;
}

// Function to create a new node with the given data
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Example usage
    struct TreeNode* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->left = createNode('F');

    // Check if the tree is a sibling tree
    if (isSiblingTree(root)) {
        printf("The tree is a sibling tree.\n");
    } else {
        printf("The tree is not a sibling tree.\n");
    }

    return 0;
}
