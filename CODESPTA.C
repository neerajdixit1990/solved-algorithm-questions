#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int find_count(long int data)
{
	long long int temp=0,i;
	if(data==0)
		return (long long int)0;
	else if((data&(data-1))==0)
        return (long long int)1;
	else if(((data-1)&(data-2))==0)
        return (long long int)2;
	else if(((data-3)&(data-2))==0)
        return (long long int)2;
	else if(((data-3)&(data-4))==0)
		return (long long int)3;
	else if(((data+1)&(data))==0)
		 return ((long long int)log2(data+1)/*/(long long int)log(2)*/);
	else if(((data+1)&(data+2))==0)
		 return ((long long int)(log2(data+2)-1)/*/(long long int)log(2)*/);
	else if(((data+2)&(data+3))==0)
		 return ((long long int)(log2(data+3)-1)/*/(long long int)(log(2))*/);
    else
    {
        for(i=data;i!=0;)
        {
            temp=temp+(long long int)(i%2);
			i=i>>1;
        }
        return (long long int)temp;
    }
}
int main()
{
    long int first,second,j;
    long long int test_cases,ans,c=32,i;
    scanf("%lld",&test_cases);
    for(i=1;i<=test_cases;i++)
    {
        scanf("%ld%ld",&first,&second);
        ans=0;
        if(first<0&&second<0)
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
			if(first*(-1)<=(second-1))
			{
				//ans=c*first*(long long int)(-1);
				ans=(long long int)first*(long long int)(-1);
				ans=(long long int)(ans)*(long long int)(c); //error line
                for(j=first*(-1);j<=second;j++)
                    ans=ans+find_count(j);
            }
            else
			{
				//ans=(second+1)*c;
				ans=(long long int)(second+1);
				ans=(long long int)(ans)*(long long int)(c);
				for(j=second*(-1)-2;j>=first;j--)
                    ans=ans+32-find_count(j*(-1)-1);
            }
        }
        printf("%lld\n",ans);
	}
    return 0;
}

