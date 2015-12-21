#include<stdio.h>
#include<math.h>
long long int loga[102]={0,0,1,1,2,2,2,2,3,3,3,
                3,3,3,3,3,4,4,4,4,4,
                4,4,4,4,4,4,4,4,4,4,
                4,5,5,5,5,5,5,5,5,5,
                5,5,5,5,5,5,5,5,5,5,
                5,5,5,5,5,5,5,5,5,5,
                5,5,5,6,6,6,6,6,6,6,
                6,6,6,6,6,6,6,6,6,6,
                6,6,6,6,6,6,6,6,6,6,
                6,6,6,6,6,6,6,6,6,6};
int main()
{
	long long int test_cases,input,i,barlength,min_cut,j,count,min_len,temp,result;
    scanf("%lld",&test_cases);
    for(i=1;i<=test_cases;i++)
    {
		scanf("%lld",&input);
        min_len=0;
        min_cut=0;
        if((input&(input-1))==0)
        {
            barlength=input;
            min_cut=0;
        }
        else
        {
			temp=input;
            while(temp!=0)
            {
                if(temp<=100)
                {
                    min_len=(long long int)min_len+(long long int)loga[temp]+(long long int)1;
                    break;
                }
                else
                {
                    temp=(long long int)temp/(long long int)2;
                    min_len=(long long int)min_len+(long long int)1;
                }
            }
			barlength=(long long int)1<<(long long int)min_len;
			
            temp=1;
            count=0;
            while(1)
            {
                result=input & temp;
                if(result)
                    break;
                temp=temp<<1;
                count=(long long int)count+(long long int)1;
            }
            min_cut=(long long int)min_len-(long long int)count;
        }
        printf("%lld %lld\n",barlength,min_cut);
    }
    return 0;
}
