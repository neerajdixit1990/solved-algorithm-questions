#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long long int test_cases,first,second,ans,i,j,limit;
    scanf("%lld",&test_cases);
    for(i=1;i<=test_cases;i++)
    {
        ans=0;
        scanf("%lld",&first);
        scanf("%lld",&second);
        if(first==0||second==0)
            ans=0;
		else if(first==1)
            ans=second;
        else if(second==1)
            ans=first;
        else if(first==-1)
            ans=(-1)*second;
        else if(second==-1)
            ans=(-1)*first;
        else if((first&(first-1))==0)
        {
             limit=(long long int)(log(first+1)/log(2));
             ans=second<<limit;
        }
        else if((second&(second-1))==0)
        {
             limit=(long long int)(log(second+1)/log(2));
             ans=first<<limit;
        }
        else if((first&(first+1))==0)
        {
             limit=(long long int)(log(first+2)/log(2));
             for(j=0;j<limit;j++)
                  ans=ans+(second<<j);
        }
        else if((second&(second+1))==0)
        {
             limit=(long long int)(log(second+2)/log(2));
             for(j=0;j<limit;j++)
                  ans=ans+(first<<j);
        }
        else
             ans=first*second;
        printf("%lld\n",ans);
    }
    return 0;
}
