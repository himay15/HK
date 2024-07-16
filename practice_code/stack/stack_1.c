#include <stdio.h>
#include <stdlib.h>

int top = -1;
int sizeofstack = 5;
int* createStack(int stackSize)
{
    int* stack = (int*) malloc(5 * sizeof(int));
    if(!stack)
    {
        printf("malloc fasiled\n");
        return NULL;
    }
    return stack;
}
void push(int *stack, int val)
{
    if(top == sizeofstack-1)
    {
        printf("stack is full \n");
        return;
    }
    ++top;
    stack[top] = val;
}

void print(int * stack)
{
    if(top == -1)
    {
        printf("stack is empty \n");
        return;
    }
    for(int i = 0 ;i <=top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int isempty()
{
    if(top == -1)
    {
        return 1;
    }
    return 0;
}
int pop(int *stack)
{
    if(isempty())
    {
        printf("stack is empty \n");
        return 0;
    }
    int val = stack[top];
    top--;
    return val;
}
int main()
{
    

    int *stack = createStack(sizeofstack);
    if(!stack)
    {
        printf("stack creation failed due to insufficent memoery \n");
        return 0;
    }

    push(stack,1);
    push(stack,2);
    push(stack,3);
    printf("top = %d\n",top);
    print(stack);

    int val = pop(stack);
    printf("popped element id %d \n",val);
    free(stack);
    return 0;
}