#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int input,temp,i,previous_ans;
	int visited[500020]={0};
    while(1)
	{
		scanf("%lld",&input);
		if(visited)
		{
		if(input==-1)
			break;
		previous_ans=0;
		//visited=(int *)calloc(1,sizeof(int)*(input+20));
		for(i=1;i<=input;i=i+1)
        {
			temp=previous_ans-i;
			if(temp>0)
			{
                if(visited[temp]==0)
			    {
				    visited[temp]=1;
					previous_ans=temp;
				}
				else
				{
					visited[previous_ans+i]=1;
					previous_ans=previous_ans+i;
				}
            }
            else
			{
				visited[previous_ans+i]=1;
				previous_ans=previous_ans+i;
			}
        }
        }
		printf("%lld\n",previous_ans);
    }
    return 0;
}
