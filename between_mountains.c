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
    long long int altitude[2][1002],test_cases,i,j,N1,N2,temp1,temp2,least_diff,k;
    scanf("%lld",&test_cases);
    for(k=0;k<test_cases;k++)
    {                   
        scanf("%lld",&N1);
        for(i=0;i<N1;i++)
            scanf("%lld",&altitude[0][i]);
        scanf("%lld",&N2);
        for(i=0;i<N2;i++)
            scanf("%lld",&altitude[1][i]);
        i=sort(altitude,N1,N2);
        least_diff=diff(altitude[0][0],altitude[1][0]);
        for(i=0,j=0;(i<N1&&j<N2);)
        {
            temp1=diff(altitude[0][i+1],altitude[1][j]);
            temp2=diff(altitude[0][i],altitude[1][j+1]);
            if(temp1<=temp2)
            {   
                i=i+1;
                if(temp1<least_diff)
                    least_diff=temp1;
            }
            else if(temp1>temp2)
            {                   
                j=j+1;               
                if(temp2<least_diff)
                    least_diff=temp2;
            }
        }
        if(i>=N1)
        {
            for(;j<N2;j++)
            {
                temp1=diff(altitude[0][N1-1],altitude[1][j]);    
                if(temp1<least_diff)
                    least_diff=temp1;
            }
        }
        else if(j>=N2)
        {
            for(;i<N1;i++)
            {
                temp1=diff(altitude[0][i],altitude[1][N2-1]);
                if(temp1<least_diff)
                    least_diff=temp1;
            }
        }
        printf("%lld\n",least_diff);
    }
    return 0;
}
