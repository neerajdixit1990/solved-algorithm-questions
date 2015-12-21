#include<stdio.h>
int main()
{
    int test_cases,i,first_hour,first_min,second_hour,second_min,count;
    int mins[12]={0,5,10,16,21,27,32,38,43,49,54,60};
	char first[9],second[9];
	scanf("%d",&test_cases);
    for(i=0;i<test_cases;i++)
    {
        scanf("%s",first);
		scanf("%s",second);
		count=0;
		first_hour=(first[0]-48)*10+first[1]-48;
		first_min=(first[3]-48)*10+first[4]-48;
		second_hour=(second[0]-48)*10+second[1]-48;
		second_min=(second[3]-48)*10+second[4]-48;
		if(first_hour!=second_hour)
		{
			count=second_hour-first_hour-1;
			if(first_hour<12)
			{
				if((first_min<=mins[first_hour])&&first_hour!=0)
					count++;
			}
			else
			{
				if((first_min<=mins[first_hour-12])&&(first_min!=0))
					count++;
			}
			if(second_hour<12)
			{
				if((second_min>mins[second_hour])&&second_hour!=0)
					count++;
			}
			else
			{
				if((second_min>mins[second_hour-12])&&second_min!=0)
					count++;
			}
			if((first_hour==11)&&(second_hour==12)&&(second_min==0))
			    count++;
			if(first_hour==11)
				count--;
		}
		else
		{
			count=0;
			if(first_hour==12||first_hour==0)
				count=0;
			else if((first_min<=mins[first_hour])&&(second_min>mins[second_hour]))
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
