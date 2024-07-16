#include <stdio.h>

void bit_pattern( int num);
void printBits(unsigned int num){
    unsigned int size = sizeof(unsigned int);
    unsigned int maxPow = 1<<((size*8)-1);
    printf("MAX POW : %u\n",maxPow);
    int i=0,j;
    for(;i<size*8;++i){
    // print last bit and shift left.
    printf("%u ",num&maxPow ? 1 : 0);
    num = num<<1;
}
    
}
int main()
{
    int num = 0;

    printf("Enter a num : ");
    scanf("%d",&num);

    //bit_pattern(num);
    printBits(num);
    return 0;
}

void bit_pattern(int num)
{
    int no_of_bit = sizeof(int);
    printf("no_of_bit %d\n",no_of_bit);
#if HK
    for (int i = 0 ;i < 31 ; i++)
    {
        printf("%d ",(num) & 1);
    }

    output : 1111 0000 0000 0000 0000 0000 0000 0000 
#endif
#if HK
    for (int i = 31 ;i > -1 ; i--)
    {
        printf("%d ",(num) & (1 << i));
    }
Output : 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 8 4 2 1
#endif
#if HK 
// this is valid for unsigned int
    int mask = 1;
    for (int i = 31 ;i > -1 ; i--)
    {
        mask = 1 << i;
        if(num & mask)
            printf("%c ",'1');
        else
            printf("%c ",'0');
    }
#endif
for(int bit=0;bit<(sizeof(unsigned int) * 8); bit++)
   {
      printf("%i ", num & 0x01);
      num = num >> 1;
   }

}

