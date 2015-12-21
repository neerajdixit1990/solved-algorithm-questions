#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int test_cases,i;
	long long int len,k,first,second,j,no_oper,count;
	char *input,temp,op;
	input=(char *)malloc(sizeof(char)*100020);
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		scanf("%s",input);
		len=strlen(input);
		scanf("%lld",&no_oper);
		for(k=0;k<no_oper;k=k+1)
		{
	//		scanf("%c",&temp);
            scanf("%c",&op);
        //    scanf("%c",&temp);
            scanf("%lld",&first);
          //  scanf("%c",&temp);
			if(op=='Q')
			{
                scanf("%lld",&second);           
				count=0;
				first=(long long int)first-(long long int)1;
				second=(long long int)second-(long long int)1;
				while(input[first]==input[second])
				{
					count=(long long int)count+(long long int)1;
					first=(long long int)first+(long long int)1;
					second=(long long int)second+(long long int)1;
				}
				printf("%lld\n",count);
			}
			else
			{
				scanf("%c",&temp);
				if(op=='R')
					input[(long long int)first-(long long int)1]=temp;
				else
				{
					input[(long long int)len+(long long int)1]='\0';
					for(j=(long long int)len-(long long int)1;j>=first;j=(long long int)j-(long long int)1)
                        input[(long long int)j+(long long int)1]=input[j];
                    input[(long long int)j+(long long int)1]=temp;
                    len=(long long int)len+(long long int)1;
                }
            }
        }
    }
    return 0;
}
