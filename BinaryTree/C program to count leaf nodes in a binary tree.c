   #include <stdio.h>
 
struct node {
    int data;
    struct node *left;
    struct node *right;
};
 
struct node* getNewNode(int data) {
  /* dynamically allocate memory for a new node */
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  
  /* populate data in new Node */
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
   
  return newNode;
}
 
/*
This function returns below 
            1
           / \
         2    3
        / \  / \
       4  5 6  7
      /
     8
*/
struct node* generateBTree(){
    // Root Node
    struct node* root =  getNewNode(1);
    // Level 2 nodes 
    root->left = getNewNode(2);
    root->right = getNewNode(3);
    // Level 3 nodes
    root->left->left = getNewNode(4);
    root->left->right = getNewNode(5);
    root->right->left = getNewNode(6);
    root->right->right = getNewNode(7);
    // Level 4 nodes
    root->left->left->left = getNewNode(8);
     
    return root;
 
}
 
/*
 Returns the count of leaf nodes in a binary tree   
*/
int countLeafNode(struct node *root){
    /* Empty(NULL) Tree */
    if(root == NULL)
        return 0;
    /* Check for leaf node */
    if(root->left == NULL && root->right == NULL)
        return 1;
    /* For internal nodes, return the sum of 
    leaf nodes in left and right sub-tree */
    return countLeafNode(root->left) + countLeafNode(root->right);
}
 
int main() {
    struct node *root = generateBTree();    
     
    /* Print number of lead nodes */
    printf("Number of leaf Node : %d", countLeafNode(root));
     
    getchar();
    return 0; 
}