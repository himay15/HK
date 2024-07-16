#include <stdio.h>

int check(int num)
{
    if(num & 1 )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    int num = 0;
    printf("Enter a num: ");
    scanf("%d",&num);
    int result = check(num);
    if(result)
        printf("Odd");
    else
        printf("Even");
    return 0;
}