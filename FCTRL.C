#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long long int test_cases,factor=5,ans,input,temp,i;
    scanf("%lld",&test_cases);
    for(i=1;i<=test_cases;i++)
    {
        ans=0;
        factor=5;
        scanf("%lld",&input);
        while(1)
        {
            temp=(long long int)(input/factor);
            ans=ans+temp;
            factor=factor*5;
            if(input<factor)
                break;
        }
        printf("%lld\n",ans);
    }
    scanf("%lld",&test_cases);
    return 0;
}
