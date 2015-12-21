#include<stdio.h>
#include<math.h>
int main()
{
	long long int input,dec,temp;
	double d;
    while(1)
    {
        scanf("%lld",&input);
        if(input==-1)
            break;
        input=input-(long long int)1;
        dec=(long long int)input%3;
        if(dec!=0)
            printf("N\n");
        else
        {
            input=(long long int)(input/(long long int)3);
            temp=(long long int)((long long int)4*input);
            temp=temp+(long long int)1;
			d=sqrt((double)temp);

			if((d-floor(d))>=-0.001 &&(d-floor(d))<=0.001)
				printf("Y\n");
			else
				printf("N\n");
        }
    }
    return 0;
}
