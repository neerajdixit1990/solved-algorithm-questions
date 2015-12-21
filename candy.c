#include <stdio.h>
int main()
{
    long long int ans,sum,avg;
    long long int input[10020],no_of_packets,i;
    while(1)
    {
        scanf("%lld",&no_of_packets);
        if(no_of_packets==-1)
            break;
        sum=0;
        ans=0;
        for(i=0;i<no_of_packets;i++)
        {
            scanf("%lld",&input[i]);
            sum=sum+input[i];
        }
        if(sum%no_of_packets!=0)
            printf("-1\n");
        else
        {
            avg=sum/no_of_packets;
            for(i=0;i<no_of_packets;i++)
            {
                if(input[i]>avg)
                    ans=ans+(input[i]-avg);
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
