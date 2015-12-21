#include<stdio.h>
int main()
{
    long long int test_cases,a,b,i,ans,mod,j;
    scanf("%lld",&test_cases);
    for(i=0;i<test_cases;i++)
    {
        scanf("%lld%lld",&a,&b);
        mod=(long long int)b%(long long int)4;
        ans=a;
        if(mod!=0)
        {   
            for(j=1;j<mod;j++)
            {   
                ans=ans*a;
                ans=(long long int)ans%(long long int)10;
            }
        }
        else
        {
            for(j=1;j<4;j++)
            {
                ans=ans*a;
                ans=(long long int)ans%(long long int)10;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
