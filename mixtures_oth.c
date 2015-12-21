#include<stdio.h>
int main()
{
	int n,i,j,k,l,mix[105][105],min,h;
 	long long int smoke[105][105];
       	while(scanf("%d",&n)!=EOF)
       	{
        	for(i=1;i<=n;i++)
             		scanf("%d",&mix[i][i]);
          	for(i=1;i<=n;i++)
             		smoke[i][i]=0;
          	for(l=2;l<=n;l++)
          	{
             		for(i=1;i<=n-l+1;i++)
             		{
                		j=i+l-1;
                		min=32767;
                		for(k=i;k<j;k++)
                		{
                   			h=(mix[i][k]*mix[k+1][j])+(smoke[i][k]+smoke[k+1][j]);
                   				if(h<min)
                   	   				min=h;
                		}
                		smoke[i][j]=min;
                		mix[i][j]=(mix[i][j-1]+mix[j][j])%100;
             		}
        	}
        	printf("%lld\n",smoke[1][n]);
       	}
	return 0;
}

