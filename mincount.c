#include <stdio.h>
int main()
{
    long long int test_cases,input,ans,i;
    scanf("%lld",&test_cases);
    for(i=1;i<=test_cases;i++)
    {
        ans=input*(input+1);
        ans=ans/6;
        printf("%lld\n",ans);
    }
    return 0;
}
