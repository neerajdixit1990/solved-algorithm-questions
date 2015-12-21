#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char input[12][102];
long long int relevance[12];
int main()
{
    long long int test_cases,i,j,temp;
    scanf("%lld",&test_cases);
    for(i=1;i<=test_cases;i++)
    {
        for(j=0;j<10;j++)
        {
            scanf("%s",input[j]);
            scanf("%lld",&relevance[j]);
        }
        temp=relevance[1];
        for(j=1;j<10;j++)
            if(relevance[j]>temp)
                temp=relevance[j];
        printf("Case #%lld:\n",i);
        for(j=0;j<10;j++)
        {
            if(relevance[j]==temp)
                printf("%s\n",input[j]);
        }
    }
    return 0;
}
