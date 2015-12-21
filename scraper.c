#include<stdio.h>
#include<stdlib.h>
int main()
{
	long int N,F,E,start,end,ele[201][2]={0},i,j,front,rear,n,flag=0;
	int *visit=NULL;
	long int *q=NULL;
    q=(long int *)calloc(1,15999999*sizeof(long int));
	scanf("%ld",&N);
	for(n=0;n<N;n++)
	{
		scanf("%ld",&F);
		scanf("%ld",&E);
		scanf("%ld",&start);
		scanf("%ld",&end);
		visit=(int *)calloc(1,50000004*sizeof(int));
		flag=0;
		front=0;	rear=0;
		for(i=0;i<E;i++)
			scanf("%ld%ld",&ele[i][0],&ele[i][1]);
		rear=(rear+1)%(F);
		q[rear]=start;
		while(front!=rear)
		{
			front=(front+1)%(F);
			i=q[front];
			visit[i]=1;
			if(i==end)
			{	flag=1;
				break;
			}
			for(j=0;j<E;j++)
			{
				if((i-ele[j][1])%ele[j][0]==0&&i>=ele[j][1])
				{	
					if((i+ele[j][0])<F&&visit[i+ele[j][0]]==0)					
					{	
						rear=(rear+1)%(F);
						q[rear]=i+ele[j][0];
					}
					if((i-ele[j][0])>=ele[j][1]&&visit[i-ele[j][0]]==0)
					{	
						rear=(rear+1)%(F);
						q[rear]=i-ele[j][0];
					}
				}
			}
		}
		if(flag==1)
			printf("\nIt is possible to move the funiture.");
		else
			printf("\nThe furniture cannot be moved.");
	}
	return 0;
}
