#include<stdio.h>
int main()
{
	int test_cases,n,m,i,j,input[120],count[11],sum,k;
	int last_index[11],init,temp,cnt;
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
    {
        scanf("%d",&n);
        scanf("%d",&m);
        sum=0;
		for(j=0;j<11;j++)
		{	count[j]=0;
		    last_index[j]=-1;
        }
		for(j=0;j<n;j++)
		{
			scanf("%d",&input[j]);
			k=input[j];
			count[k]=count[k]+1;
		}
		init=9;
		while(count[init]==0)
		    init--;
        temp=0;
        for(j=init;j>=input[m];j--)
        {
            if(count[j]==0)
                continue;
            for(k=temp,cnt=0;cnt<n;)
            {
                if(input[k]==j)
                {
					last_index[j]=(k+1)%n;
                    temp=(k+1)%n;
                }
                cnt++;
                k=(k+1)%n;
            }
        }
		init=input[m]+1;
        while(count[init]==0&&init<=9)
            init++;
        if(init>9)
            temp=0;
        else
            temp=last_index[init];
		for(j=9;j>input[m];j--)
			sum=sum+count[j];
		
		for(j=temp;j!=m;)
		{
            if(input[j]==input[m])
                sum++;
            j=(j+1)%n;
        }
        sum++;
        printf("%d\n",sum);
    }
    return 0;
}
