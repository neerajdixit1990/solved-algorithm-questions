#include<stdio.h>
int main()
{
    long long int n,ans,i,input;
    scanf("%lld",&n);
    ans=0;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&input);
        ans=(long long int)((long long int)ans^(long long int)input);
    }
    printf("%lld",ans);
    return 0;
}
