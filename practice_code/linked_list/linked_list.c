#include "ll_lib.h"

int main()
{
/*
    DUMMY NODE APPROACH -> when head is passed as pass by and value and return is void
    //node_t head;
    //head.data = 0;
    //head.next = NULL;  
    addNodeAtEnd(&head,10);
    no need to return head from addNodeAtEnd
*/
    node_t *head = NULL;
    display(head);

    head = addNodeAtEnd(head,9);
    display(head);
    addNodeAtEnd(head,9);
    addNodeAtEnd(head,9);
    addNodeAtEnd(head,9);

    display(head);

    //head = reverselist(head);
    //display(head);

    head = addplus1(head);

    display(head);



    return 0; 
}