#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
}node_t;

node_t* createnode(int data);
void addNodeAtFront(node_t *head,int data);
node_t* addNodeAtEnd(node_t *tail,int data);
//void addNodeAtEnd(node_t *tail,int data);
void display(node_t* head);
void deletenode(node_t *head);
void deletelist(node_t *head);
node_t* reverselist(node_t *head);

// Amazon
node_t* addplus1(node_t *head);
