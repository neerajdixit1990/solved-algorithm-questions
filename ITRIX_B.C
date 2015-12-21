#include<stdio.h>
int main()
{
    long long int input,no_digit,first,last,test_cases,i,factor=4,j,range;
    scanf("%lld",&test_cases);
    for(i=0;i<test_cases;i=i+1)
    {
        scanf("%lld",&input);
        no_digit=0;
        factor=4;
        first=0;
        while(1)
        {
			if((first+factor)>=input)
				break;
			first=first+factor;
			factor=(long long int)factor*(long long int)4;
            no_digit=no_digit+1;
		}
		last=first+factor;
		no_digit=no_digit+1;
		for(j=0;j<no_digit;j=j+1)
		{
			range=(long long int)(last-first)/(long long int)4;
			if((first+range)>=input)
			{
				last=first+range;
				printf("2");
			}
			else if((first+(long long int)range*(long long int)2)>=input)
			{
				 last=first+((long long int)range*(long long int)2);
				 first=first+range;
				 printf("3");
			}
			else if((first+(long long int)range*(long long int)3)>=input)
			{
				 last=first+((long long int)range*(long long int)3);
				 first=first+((long long int)range*(long long int)2);
				 printf("5");
			}
			else
			{
				first=last-range;
				printf("7");
			}
		}
		printf("\n");
    }
    return 0;
}
