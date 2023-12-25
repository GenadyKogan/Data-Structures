#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary tree
struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with the given key
struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create the mirror of a binary tree
struct TreeNode* createMirrorTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    // Create a new node with the same key as the current root
    struct TreeNode* mirrorRoot = createNode(root->key);

    // Recursively create the mirror of the right subtree as the left subtree of the new node
    mirrorRoot->left = createMirrorTree(root->right);

    // Recursively create the mirror of the left subtree as the right subtree of the new node
    mirrorRoot->right = createMirrorTree(root->left);

    return mirrorRoot;
}

// Function to print in-order traversal of a binary tree
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->key);
        inOrderTraversal(root->right);
    }
}

int main() {
    // Create a sample binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Print the original tree
    printf("Original tree (in-order): ");
    inOrderTraversal(root);
    printf("\n");

    // Create the mirror tree
    struct TreeNode* mirrorRoot = createMirrorTree(root);

    // Print the mirror tree
    printf("Mirror tree (in-order): ");
    inOrderTraversal(mirrorRoot);
    printf("\n");

    return 0;
}
