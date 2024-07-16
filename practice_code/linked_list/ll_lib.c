#include "ll_lib.h"

node_t* createnode(int value)
{
    node_t * newnode = (node_t*) malloc(sizeof(node_t));
    if(!newnode)
    {
        printf("dynamic memory allocation is failed \n");
        return NULL;
    }
    newnode->data = value;
    newnode->next = NULL;
    //printf("newnode %p \n",newnode);
    return newnode;
}

node_t* addNodeAtEnd(node_t* head,int data)
{
    node_t * current = head;

    node_t* newNode= createnode(data);

    if(!head)
    {
        printf("heaad is null \n");
    }
    //printf("neWnode %p \n",newNode);
    if(!newNode)
    {
      //  printf("newnode return null \n");
    }

    if(!head)
    {
        head = newNode;
        printf("added node at head \n");
        return head;
    }

    while(current)
    {
        if(!current->next)
        {
            current->next = newNode;
            printf("newnode added at last \n");
            break;
        }

        current = current->next;
    }
    return head;

}

void display(node_t *head)
{
    node_t * current = head;
    if(!head)
    {
        printf("list is empty \n");
        return;
    }

    while(current)
    {
        printf(" | %d | %p |-->",current->data,current->next);
        current = current->next;
    }
    printf("\n");
}

node_t* reverselist(node_t* head)
{
    
    node_t* prev = NULL;
    node_t* current = head;
    node_t* next = NULL;

    while (current) {
        next = current->next;  // Save next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move pointers one position ahead
        current = next;
    }
    head = prev;
    return head;
}

node_t * addplus1(node_t* head)
{
    head = reverselist(head);
    node_t *current = head;
    int sum = 0, carry =1;
    
    if(!head)
    {
        printf("lsit is empty , can't add 1 \n");
        return head;
    }
    display(current);
    while(current)
    {
        sum = current->data + carry;
        carry = sum / 10;
        current->data = sum % 10;
        if(!current->next)
        {
            printf("1 \n");
            if(carry)
            {
                printf("2\n");
                current->next = createnode(carry);
                break;
            }
        }
        current = current->next;  
    }
    return(reverselist(head));
}