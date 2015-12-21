#include<stdio.h>
int main()
{
    long long int test_cases,m,n,temp1,temp2,input1,input2,ans,lcm;
    while(1)
    {
        scanf("%lld%lld",&m,&n);
        if(m==0&&n==0)
            break;
        input1=m;
        input2=n;
        while( m!= n) // execute loop until m == n
        {
            if( m > n)
                m= m - n; // large - small , store the results in large variable
            else
                n= n - m;
        }
        ans=(long long int)input1*(long long int)input2;
        lcm=(long long int)ans/(long long int)m;
        temp1=(long long int)lcm/(long long int)input1;
        temp2=(long long int)lcm/(long long int)input2;
        ans=(long long int)temp1*(long long int)temp2;
        printf("%lld\n",ans);
    }
    return 0;
}
