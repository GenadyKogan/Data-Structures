#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a tree node
struct TreeNode* createNode(int key) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the second maximum key in a binary search tree
int findSecondMax(struct TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return -1;
    }

    struct TreeNode* maxNode = root;
    struct TreeNode* secondMaxNode = NULL;

    while (maxNode->right != NULL) {
        secondMaxNode = maxNode;
        maxNode = maxNode->right;
    }

    if (maxNode->left != NULL) {
        maxNode = maxNode->left;
        while (maxNode->right != NULL) {
            maxNode = maxNode->right;
        }
        return maxNode->key;
    } else if (secondMaxNode != NULL) {
        return secondMaxNode->key;
    }

    return -1;
}

// Function to free the memory of a tree
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    // Example 1
    struct TreeNode* tree1 = createNode(50);
    tree1->left = createNode(30);
    tree1->right = createNode(70);
    tree1->left->left = createNode(20);
    tree1->left->right = createNode(40);
    tree1->right->left = createNode(60);
    tree1->right->right = createNode(80);

    int result1 = findSecondMax(tree1);
    printf("Example 1: The second maximum key is: %d\n", result1);

    freeTree(tree1);

    // Example 2
    struct TreeNode* tree2 = createNode(70);
    tree2->left = createNode(50);
    tree2->right = createNode(80);
    tree2->left->left = createNode(30);
    tree2->left->right = createNode(60);
    tree2->right->left = createNode(75);
    tree2->right->right = createNode(90);

    int result2 = findSecondMax(tree2);
    printf("Example 2: The second maximum key is: %d\n", result2);

    freeTree(tree2);

    return 0;
}
