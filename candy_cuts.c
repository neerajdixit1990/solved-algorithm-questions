#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long int test_cases,input,i,sum,barlength,min_cut,j,count,min_len,temp;
    scanf("%lld",&test_cases);
    for(i=1;i<=test_cases;i++)
    {
        scanf("%lld",&input);
        sum=0;
        min_len=0;
        min_cut=0;
        if((input&(input-1))==0)
        {
            min_len=input;
            min_cut=0;
        }
        else
        {
            /*temp=(long long int)(log(input)/log(2));
            temp++;
            barlength=1;
			barlength=barlength<<temp;*/
			temp=input;
            while(input!=0)
            {
                input=(long long int)(input/2);
                min_len++;
            }
			barlength=1<<min_len;
			min_len=barlength;
			input=temp;
            while(1)
            {
                    barlength=(long long int)(barlength/2);
                    temp=barlength+sum;
                    if(temp<input)
                    {
                        sum=sum+barlength;
                        min_cut++;
                    }
                    else if(temp>input)
                        min_cut++;
                    else
                    {
                        min_cut++;
                        break;
                    }
            }
        }
        printf("%lld %lld\n",min_len,min_cut);
    }
    return 0;
}
