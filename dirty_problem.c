#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    long long int test_cases,N,K,i,a,limit,flag,first,second;
    scanf("%lld",&test_cases);
    for(i=1;i<=test_cases;i++)
    {
        scanf("%lld",&N);
        scanf("%lld",&K);
        flag=0;
        if(K!=1)
        {
            first=K;
            second=K*(K-1);
            second=(long long int)second/2;
            limit=(long long int)(N/K);
            for(a=1;a<=limit;a++)
            {
                if((N-first*a)>0)
                    if(((N-first*a)%second)==0)
                        flag=1;
                if(flag==1)
                    break;
            }
        }
        else
            flag=1;
        if(flag==1)
            printf("Padam tharumaru machi!\n");
        else
            printf("Padam sotha machi!\n");
    }
    return 0;
}
