#include<stdio.h>
int main()
{
    long long int input;
    scanf("%lld",&input);
    if(!(input&(input-1)))
        printf("TAK\n");
    else
        printf("NIE\n");
    return 0;
}
