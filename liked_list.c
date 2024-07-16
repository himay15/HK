#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node * Createlist(struct node * head, int value)
{
    //struct node * newnode = createnode();
    struct node * newnode = (struct node *) malloc(sizeof(struct node));
    if(!newnode)
    {
        printf("malloc failed\n");
        return NULL;
    }
    
    newnode->data = value;
    newnode->next = NULL;
    if(!head)
    {
        head = newnode;
         printf("head value %p and head address %p\n",head,&head);
    }
    else
    {
        struct node* current = head;
        while(current->next)
        {
            current = current->next;
        }
        current->next = newnode;
    }
 printf("newnode value %p and newnode address %p\n",newnode,&newnode);
    return head;
}

void printlist(struct node *head)
{
    if(!head)
    {
        printf("list is empty\n");
        return;
    }
    struct node *current = head;
    while(current)
    {
        printf(" %d | %p |-->",current->data,current->next);
        current = current->next;
    }
    return;
}

void freelist(struct node *head)
{
    struct node *current = head;
    if(!head)
    {
        printf("list is empty\n");
        return;
    }
    while(current)
    {
        free(current);
        current = current->next;
    }


}

int main()
{
    struct node * head =  NULL;

    int data = 5;

    head = Createlist(head,data);
    //printf("head value %p and head address %p\n",head,&head);

    if(!head)
    {
        printf("list is empty and failed to create list\n");
    }    

    struct node * current =  Createlist(head,10);
    //printf("2nd node value %p and  address %p\n",current,&current);
    current = Createlist(head,6);
    //printf("3rd node value %p and  address %p\n",current,&current);

    printlist(head);
    freelist(head);

    return 0;
}