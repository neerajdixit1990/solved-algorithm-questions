#include<stdio.h>
int main()
{
	long long int input,ans;
	while(1)
	{
		scanf("%lld",&input);
		if(input==0)
			break;
		ans=(long long int)input*(long long int)(input+1);
		ans=(long long int)ans*(long long int)(2*input+1);
		ans=(long long int)ans/(long long int)6;
		printf("%lld\n",ans);
	}
	return 0;
}
