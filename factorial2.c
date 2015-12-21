#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long double *fact;
    int i,input_data,test_cases;
    scanf("%d",&test_cases);
    fact=(long double *)calloc(1,sizeof(long double)*102);
    fact[0]=1;
    fact[1]=1;
    for(i=2;i<=100;i++)
        fact[i]=fact[i-1]*i;
    for(i=1;i<=test_cases;i++)
    {
		scanf("%d",&input_data);
        printf("%lle\n",fact[input_data]);
    }
    return 0;
}
