#include<stdio.h>
#include<stdlib.h>
int main()
{
	long int test_cases,empty_wt,full_wt,i,j,temp1,temp2;
	long int no_deno,*monetary_val,*coin_wt,**tab;
	scanf("%ld",&test_cases);

	scanf("%ld",&empty_wt);
	scanf("%ld",&full_wt);
	scanf("%ld",&no_deno);
	monetary_val=(long int *)malloc(sizeof(long int)*no_deno);
	coin_wt=(long int *)malloc(sizeof(long int)*no_deno);
	tab=(long int **)malloc(sizeof(long int *)*no_deno);
	for(i=0;i<no_deno;i++)
		tab[i]=(long int *)malloc(sizeof(long int)*(full_wt-empty_wt)+1);
	for(i=0;i<no_deno;i++)
		scanf("%ld%ld",monetary_val[i],coin_wt[i]);
	for(i=0;i<no_deno;i++)
	{
		for(j=0;j<=(full_wt-empty_wt);j++)
		{
			if(i==0&&j<coin_wt[i])
			{
				temp1=0;
				temp2=0;
			}
			else if(i==0&&j>=coin_wt[i])
			{
				temp1=0;
				temp2=tab[i][j-coin_wt[i]]+monetary_val[i];
			}
			else if(i!=0&&j<coin_wt[i])
			{
				temp1=tab[i-1][j];
				temp2=0;
			}
			else
			{
				temp1=tab[i-1][j];
				temp2=tab[i][j-coin_wt[i]]+monetary_val[i];
			}
			if(temp1>=temp2)
				tab[i][j]=temp1;
			else
				tab[i][j]=temp2;
		}
	}
	
}
