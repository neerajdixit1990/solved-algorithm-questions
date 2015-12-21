#include<stdio.h>
#include<stdlib.h>
long long int no_of_bits[]={0,1,1,2,1,2,1,3,1,2,2,3,2,3,3,4};
/*long long int find_count(long long int data)
{
	long long int temp=0,i;
	if(data==0)
		return 0;
	else if((data&(data-1))==0)
		return 1;
	else if(((data-1)&(data-2))==0)
		return 2;
	else if(((data-3)&(data-2))==0)
		return 2;
	else if(((data-3)&(data-4))==0)
		return 3;
	else if(((data+1)&(data))==0)
		 return log(data+1)/log(2);
	else if(((data+1)&(data+2))==0)
		 return (log(data+2)/log(2)-1);
	else if(((data+2)&(data+3))==0)
		 return (log(data+3)/log(2)-1);
	else
	{
		for(i=data;i!=0;)
		{
			temp=temp+(i%2);
			i=i>>1;
		}
		return temp;
	}
}*/
long long int find_count(long int data)
{
     long long int ans=0,i;
     for(i=0;i<8;i++)
     {
         ans=ans+no_of_bits[data&0x000000000000000F];
         data=data>>4;
     }
     return ans;
}
int main()
{
	long long int test_cases,ans=0;
	long int first,second,i,j;
	scanf("%lld",&test_cases);
	for(i=1;i<=test_cases;i++)
	{
		scanf("%ld%ld",&first,&second);
		ans=0;
		/*if(first<0&&second<0)
		{
			for(j=first;j<=second;j++)
				 ans=ans+c-find_count(j*(-1)-1);
		}
		else if(first>=0&&second>=0)
		{
			 for(j=first;j<=second;j++)
				 ans=ans+find_count(j);
		}
		else
		{
			if((first*(-1)-1)<=second)
			{
				ans=c*first*(-1);
				for(j=first*(-1);j<=second;j++)
					ans=ans+find_count(j);
			}
			else
			{
				ans=(second+1)*c;
				for(j=second*(-1)-2;j>=first;j--)
					ans=ans+c-find_count(j*(-1)-1);
			}
		}*/
		for(j=first;j<=second;j++)
            ans=ans+find_count(j);
		printf("%lld\n",ans);
	}
	return 0;
}
