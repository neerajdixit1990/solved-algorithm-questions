#include <stdio.h>
int main()
{
    long long int test_cases,i,no_of_children,j,input,sum;
    scanf("%lld",&test_cases);
    for(i=0;i<test_cases;i++)
    {
        sum=0;
        scanf("%lld",&no_of_children);
        for(j=0;j<no_of_children;j++)
        {
            scanf("%lld",&input);
            sum=sum+input;
            sum=sum%no_of_children;
        }
        if(sum==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
