#include<stdio.h>

int main()
{
	int N,M,final_ans,i,j,flag,first,second,third;
	int input[102][102],tab[102][102];
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			scanf("%d",&input[i][j]);
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
		{
			if(i==0&&j==0)
				tab[i][j]=input[0][0];
			else if(i==0&&j!=0)
			{
				if(input[i][j]<input[i][j-1])
					tab[i][j]=input[i][j];
				else
					 tab[i][j]=input[i][j-1];
			}
			else if(i!=0&&j==0)
				tab[i][j]=tab[i-1][j]+input[i][j];
			else
			{
				first=input[i][j]+tab[i-1][j-1];
				second=input[i][j]+tab[i-1][j];
				if(j>=(M-1))
					third=30000;
				else
					third=input[i][j]+tab[i-1][j+1];
				if(first>second)
				{
					if(third>second)
						tab[i][j]=second;//flag=0;
					else
						tab[i][j]=third;//flag=1;
				}
				else
				{
					if(first>third)
						tab[i][j]=third;//flag=1;
					else
						tab[i][j]=first;//flag=-1;
				}
			}
		}
	}
	final_ans=tab[N-1][0];
	for(j=1;j<M;j++)
	{
		if(final_ans>tab[N-1][j])
			final_ans=tab[N-1][j];
	}
	printf("%d",final_ans);
	return 0;
}
