#include<stdio.h>
long long int diff(long long int a,long long int b)
{
    if(a>b)
        return(a-b);
    else
        return(b-a);
}
int sort(long long int altitude[2][1002],long long int N1,long long int N2)
{
    int i,j;
    long long int temp;
    for(i=0;i<N1;i++)
    {
        for(j=i+1;j<N1;j++)
        {
            if(altitude[0][i]>altitude[0][j])
            {
                temp=altitude[0][i];
                altitude[0][i]=altitude[0][j];
                altitude[0][j]=temp;
            }
        }
    }
    for(i=0;i<N2;i++)
    {
        for(j=i+1;j<N2;j++)
        {
            if(altitude[1][i]>altitude[1][j])
            {
                temp=altitude[1][i];
                altitude[1][i]=altitude[1][j];
                altitude[1][j]=temp;
            }
        }
    }
    return 0;
}
int main()
{
    long long int altitude[2][1002],test_cases,i,j,N1,N2,temp,k,min;
    scanf("%lld",&test_cases);
    for(k=0;k<test_cases;k++)
    {                   
        scanf("%lld",&N1);
        for(i=0;i<N1;i++)
            scanf("%lld",&altitude[0][i]);
        scanf("%lld",&N2);
        for(i=0;i<N2;i++)
            scanf("%lld",&altitude[1][i]);
        min=100000000000;
        i=sort(altitude,N1,N2);
        for(i=0;i<N1;i++)
        {
            for(j=i+1;j<N2;j++)
            {
                temp=diff(altitude[0][i],altitude[1][j]);
                if(temp<min)
                    min=temp;
            }
        }
        printf("%lld\n",min);
    }
    return 0;
}
