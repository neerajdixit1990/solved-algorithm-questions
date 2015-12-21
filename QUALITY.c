#include<stdio.h>
int main()
{
    long long int p[3],tot_time,test_case=1;
    int a,i,count;
    while(scanf("%lld",&p[0])!=EOF)
    {
        count=0;
        tot_time=0;
        if(p[0]!=0)
        {   count++;
            tot_time=(long long int)tot_time+(long long int)p[0];
        }
        for(i=1;i<3;i++)
        {
            scanf("%lld",&p[i]);
            if(p[i]!=0)
            {   count++;
                tot_time=(long long int)tot_time+(long long int)p[i];
            }
        }
        for(i=0;i<3;i++)
        {
            scanf("%d",&a);
            if(a==1||p[i]==0)
                continue;
            tot_time=(long long int)tot_time+((long long int)a-(long long int)1)*(long long int)1200;
        }
        printf("team %lld: %d, %lld\n",test_case,count,tot_time);
        test_case=(long long int)test_case+(long long int)1;
    }
    return 0;
}
