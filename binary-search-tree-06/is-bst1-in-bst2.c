#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node
struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to check if a key is present in a binary search tree
bool search_in_binary_tree(struct TreeNode* root, int key) {
    if (root == NULL) {
        return false;
    }

    if (root->key == key) {
        return true;
    } else if (key < root->key) {
        return search_in_binary_tree(root->left, key);
    } else {
        return search_in_binary_tree(root->right, key);
    }
}

// Function to check if tree x is a subtree of tree y
bool isBST1inBST2(struct TreeNode* x, struct TreeNode* y) {
    // Base case: If x is NULL, then it is a subtree of y
    if (x == NULL) {
        return true;
    }

    // Check if the key at the current node x is present in the tree rooted at y
    bool is_current_key_present = search_in_binary_tree(y, x->key);

    // Recursively check left and right subtrees
    return is_current_key_present && isBST1inBST2(x->left, y) && isBST1inBST2(x->right, y);
}

// Example usage
int main() {
    // Create nodes for the first tree
    struct TreeNode* tree1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree1->key = 5;
    tree1->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree1->left->key = 3;
    tree1->left->left = NULL;
    tree1->left->right = NULL;
    tree1->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree1->right->key = 7;
    tree1->right->left = NULL;
    tree1->right->right = NULL;

    // Create nodes for the second tree
    struct TreeNode* tree2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree2->key = 10;
    tree2->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree2->left->key = 5;
    tree2->left->left = NULL;
    tree2->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree2->left->right->key = 8;
    tree2->left->right->left = NULL;
    tree2->left->right->right = NULL;
    tree2->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree2->right->key = 15;
    tree2->right->left = NULL;
    tree2->right->right = NULL;

    // Create nodes for the third tree
    struct TreeNode* tree3 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree3->key = 1;
    tree3->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree3->left->key = 2;
    tree3->left->left = NULL;
    tree3->left->right = NULL;
    tree3->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    tree3->right->key = 3;
    tree3->right->left = NULL;
    tree3->right->right = NULL;

    // Check if the first tree is a subtree of the second tree
    bool result1 = isBST1inBST2(tree1, tree2);
    // Check if the first tree is a subtree of the third tree
    bool result2 = isBST1inBST2(tree1, tree3);

    // Print the results
    printf(result1 ? "Tree 1 is a subtree of Tree 2.\n" : "Tree 1 is not a subtree of Tree 2.\n");
    printf(result2 ? "Tree 1 is a subtree of Tree 3.\n" : "Tree 1 is not a subtree of Tree 3.\n");

    // Free allocated memory
    free(tree1->right);
    free(tree1->left);
    free(tree1);

    free(tree2->left->right);
    free(tree2->left);
    free(tree2->right);
    free(tree2);

    free(tree3->right);
    free(tree3->left);
    free(tree3);

    return 0;
}
