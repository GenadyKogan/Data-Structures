#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


bool isDegenerate(struct Node* node) {

    if (node == NULL)
        return true;


    if (node->left != NULL && node->right != NULL)
        return false;


    if (node->left != NULL)
        return isDegenerate(node->left);
    if (node->right != NULL)
        return isDegenerate(node->right);

    return true;x
}

// Driver code
int main() {
    // Create a sample binary tree
// test 1
//    struct Node* root = createNode(1);
//    root->left = createNode(2);
//    root->right = createNode(3);
//    root->left->left = createNode(4);
//    root->left->right = createNode(5);

// test 2
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->left->right = createNode(3);
    root->left->right->left = createNode(4);


// test 3
//    struct Node* root = createNode(1);
//    root->right = createNode(2);
//    root->right->right = createNode(3);
//    root->right->right->right = createNode(4);

// test 4
//    struct Node* root = createNode(1);
//    root->right = createNode(2);
//    root->left = createNode(3);
//    root->left->left = createNode(5);
//    root->left->left->left = createNode(4);


    // Check if the binary tree is degenerate
    if (isDegenerate(root))
        printf("The binary tree is degenerate.\n");
    else
        printf("The binary tree is not degenerate.\n");

    return 0;
}
