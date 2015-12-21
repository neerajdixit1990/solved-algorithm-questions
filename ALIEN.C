#include<stdio.h>
int main()
{
	long long int cost[100020],result=0,At,Bt,start=0,sum=0,i,temp,test_cases,k,count;
	long long int count_final;
	scanf("%lld",&test_cases);
	for(k=0;k<test_cases;k=k+1)
	{
	    sum=0;
	    result=0;
	    start=0;
		count=0;
		count_final=0;
        scanf("%lld%lld",&At,&Bt);
	    for(i=0;i<At;i=i+1)
            scanf("%lld",&cost[i]);
        for(i=0;i<At;)
	    {
            temp=sum+cost[i];
            if(temp<=Bt)
            {   
                sum=temp;
				i=i+1;
				count=count+1;
				if(count>=count_final)
				{
					if(count==count_final)
					{
						if(sum<result)
							result=sum;
					}
					else
					{
						count_final=count;
						result=sum;
					}
				}
            }
            else
		    {   
                if(sum==0)     //change made
			    {
				    start=start+1;
				    i=i+1;
                }
                else
                {
				   /*	if(count>=count_final)
					{
						result=sum;
						count_final=i-start;
					}*/
                    sum=sum-cost[start];
					start=start+1;
					count=count-1;
                }
            }
        }
		printf("%lld %lld\n",result,count_final);
	}
    return 0;
}
/*

Initially the sum comes close to the highest but then next term becomes higher
until the sum becomes 0 and then the cost optimizes obtained before
Check working of yhis test case

*/
