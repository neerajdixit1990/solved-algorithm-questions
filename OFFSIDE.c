#include<stdio.h>
int main()
{
    int A,D,attacker[15],defender[15],i,no_attacker,first,second,min;
    while(1)
    {
        min=30000;
        scanf("%d",&A);
        scanf("%d",&D);
        if((A==0)&&(D==0))
            break;
        for(i=0;i<A;i++)
        {
            scanf("%d",&attacker[i]);
            if(attacker[i]<min)
                min=attacker[i];
        }
        for(i=0;i<D;i++)
        {
            scanf("%d",&defender[i]);
            if(i==0)
                first=defender[i];
            else if(i==1)
            {
                if(first<defender[i])
                    second=defender[i];
                else
                {
                    second=first;
                    first=defender[i];
                }   
            }
            else if(defender[i]<second)
            {
                if(defender[i]>first)
                    second=defender[i];
                else if(defender[i]<first)
                {
                     second=first;
                     first=defender[i];
                }
                else
                    second=first;
            }
        }
        
        if(min<second)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
