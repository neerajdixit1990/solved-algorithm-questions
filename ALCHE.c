#include<stdio.h>
int main()
{
    long long int first,second,t1,t3;
    while(1)
    {
        scanf("%lld",&first);
        scanf("%lld",&second);
        if(first==-1&&second==-1)
            break;
        t1=first*37;
        t3=second*1000;
        if(t1==t3)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
