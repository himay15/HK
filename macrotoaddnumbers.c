#include <stdio.h>

#define add(a,b,sum) {sum = (a+b)}

int main()
{
    int a = 5;
    int b = 10;
    int sum = 0;
    
    printf("%d\n",sum=(a+b));
    printf("result = %d\n", add(a,b,sum));
    return 0;
}