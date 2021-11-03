#include <stdio.h>  
#include <stdlib.h>   
//Represent a node of the singly linked list  
struct node{  
    int data;  
    struct node *next;  
};      
   
//Represent the head of the singly linked list  
struct node *head = NULL;  
   
//addNode() will add a new node to the list  
void addNode(int data) {  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->next = NULL;  
      
    //Checks if the list is empty  
    if(head == NULL) {  
        //If list is empty, head will point to new node  
        head = newNode;  
    }  
    else {  
        struct node *current = head;  
        while(current->next != NULL) {  
            current = current->next;  
        }  
        //newNode will be added after last node of the list  
        current->next = newNode;  
    }  
}  
   
//swapLastWithFirst() will swap head node with the last node of the list  
void swapLastWithFirst() {  
    struct node *current = head, *temp = NULL, *index = NULL;  
      
    //If list is empty, then display the list as it is  
    if(head == NULL) {  
        return;  
    }  
    else {  
        //After the loop, current will point to last element and index will point to second last element  
        while(current->next != NULL) {  
            index = current;  
            current = current->next;  
        }  
          
        //If list contains only one node, then display list as it is  
        if(head == current) {  
            return;  
        }  
        //If list contains only two nodes, then swap the head node with current node  
        else if(head->next == current) {  
            temp = head;  
            //head will point to last node i.e. current  
            head = current;  
            //node next to new head will be the last node  
            head->next = temp;  
            //Node next to last element will be null  
            temp->next = NULL;  
        }  
        else {  
            temp = head;  
            //head will point to last node i.e. current  
            head = current;  
            //Detach the list from previous head and add it after new head  
            head->next = temp->next;  
            //Previous head will become last node of the list  
            index->next = temp;  
            //Node next to last element will be null  
            temp->next = NULL;  
        }  
    }  
}  
      
//display() will display all the nodes present in the list  
void display() {  
    //Node current will point to head  
    struct node *current = head;  
      
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    while(current != NULL) {  
        //Prints each node by incrementing pointer  
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
      
int main()  
{  
    //Add nodes to the list  
    addNode(1);  
    addNode(2);  
    addNode(3);  
    addNode(4);  
   
    printf("Originals list: \n");  
    display();  
      
    //Swaps Last node with first node  
    swapLastWithFirst();  
      
    printf("List after swapping the first node with last: \n");  
    display();  
   
    return 0;  
}
