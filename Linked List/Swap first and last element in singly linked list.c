#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void swapFirstAndLast(struct node **head)
{
    // don't bother unless we have a list of at least two nodes
    if (!*head || !(*head)->next)
        return;

    // start with the head's next pointer (the second node in the list)
    struct node **pp = &(*head)->next;

    // walk the pointer-to-pointer down the list, each time grasping
    //  the next node's "next" pointer address until we reach a node
    //  whose 'next' is NULL. When that happens, `pp` will hold the
    //  address of the pointer pointing to the last node in the list
    while (*pp && (*pp)->next)
        pp = &(*pp)->next;

    // swap the pointer held in *head with *pp
    struct node *tmp = *head;
    *head = *pp;
    *pp = tmp;

    // save new head's next pointer to be the old head's next
    (*head)->next = (*pp)->next;

    // and finally, terminate the list.
    (*pp)->next = NULL;
}

void print_list(const struct node *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    fputc('\n', stdout);
}

int main()
{
    struct node *head = NULL, **pp = &head;
    for (int i=1; i<=5; ++i)
    {
        *pp = malloc(sizeof **pp);
        (*pp)->data = i;
        pp = &(*pp)->next;
    }
    *pp = NULL;

    print_list(head);

    swapFirstAndLast(&head);

    print_list(head);
}