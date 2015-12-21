#include<stdio.h>
int main()
{
    int limit1,limit2,first[10020],second[10020],i,j;
    long long int result,first_sum,second_sum;
    while(1)
    {
        scanf("%d",&limit1);
        if(limit1==0)
            break;
        for(i=0;i<limit1;i++)
            scanf("%d",&first[i]);
        scanf("%d",&limit2);
        for(i=0;i<limit2;i++)
            scanf("%d",&second[i]);
		result=0;
		first_sum=0;
		second_sum=0;
        for(i=0,j=0;(i<limit1)&&(j<limit2);)
        {
			if(first[i]<second[j])
				first_sum=first_sum+(long long int)first[i++];
			else if(first[i]>second[j])
                 second_sum=second_sum+(long long int)second[j++];
            else
            {
				if(first_sum>second_sum)
					result=result+(long long int)first_sum;
				else
					result=result+(long long int)second_sum;
				result=result+(long long int)first[i];
				i++;
				j++;
				first_sum=0;
				second_sum=0;
			}
		}
		while(i<limit1)
			first_sum=first_sum+(long long int)first[i++];
		while(j<limit2)
			second_sum=second_sum+(long long int)second[j++];
		if(first_sum>second_sum)
			result=result+(long long int)first_sum;
		else
			result=result+(long long int)second_sum;
        printf("%lld\n",result);
    }
    return 0;
}
