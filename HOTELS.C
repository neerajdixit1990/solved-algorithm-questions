#include<stdio.h>
int main()
{
	long long int cost[300020],result=0,N,M,start=0,sum=0,i,temp;
	scanf("%lld%lld",&N,&M);
	for(i=0;i<N;i++)
		scanf("%lld",&cost[i]);
	for(i=0;i<N;)
	{
        temp=sum+cost[i];
        if(temp<=M)
        {   
            sum=temp;
			i=i+1;
			if(sum>result)
				result=sum;
        }
        else
		{   if(result==0)
			{
				start=start+1;
				i=i+1;
			}
            else
            {
                if(sum>result)
                    result=sum;
                sum=sum-cost[start];
                start=start+1;
            }
        }
	}
    printf("%lld",result);
    return 0;
}
