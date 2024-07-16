#include <stdio.h>
#include <stdlib.h>
struct stack 
{
    int arraysize;
    int top;
    int *elements;
};
typedef struct stack stack_t;
void create_stack(stack_t *stack,int stacksize);
void destroy_stack(stack_t *stack);
int isempty(stack_t *stack);
void push(stack_t *stack,int val);
int isfull(stack_t *stack);
int pop(stack_t *stack);

int main()
{
    stack_t stack;
    int arr[5]={1,2,4,5,7};
    int i=0;
    int val;
    create_stack(&stack,5);
     
    for(i=0;i<5;i++)
    {
        push(&stack,arr[i]);
       // printf("%d",stack.top);
    }
    for (i=0;i<5;i++)
    {
        printf("%d ",stack.elements[i]);
    }
    printf("top %d\n",stack.top);
    for(i=0;i<5;i++)
    {
        val = pop(&stack);
        printf("%d ",val);
    }
    return 0;
}
void create_stack(stack_t *stack,int stacksize)
{
    stack->top = -1;
    stack->arraysize = stacksize;
    stack->elements = (int *)malloc(sizeof(int)*stacksize);
    if(!stack->elements)
    {
        printf("malloc failed");
        return;
    }
    
}
int isfull(stack_t *stack)
{
    if(stack->top == stack->arraysize - 1)
    return 1;
    return 0;
}
void push(stack_t *stack ,int val)
{
    if(isfull(stack))
    {
        printf("stack is full\n");
        return;
    }
    stack->top++;
    stack->elements[stack->top] = val;
}
int isempty(stack_t *stack)
{
    if(stack->top == -1)
    {
        return 1;
    }
    return 0;
    
}
int pop(stack_t *stack)
{
    if(isempty(stack))
    {
        printf("stack is empty\n");
        return 0;
    }
    int result = stack->elements[stack->top];
    --stack->top;
    
    return result; 
}