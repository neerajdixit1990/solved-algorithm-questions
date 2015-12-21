#include<stdio.h>
int cost[102],fun[102],table[102][502];
int get_cost(int i,int j)
{
    int temp1,temp2,c;
    if(i==0)
    {
        if(j<cost[i])
            return 0;
        else if(j>=cost[i]&&fun[i]>0)
            return cost[i];
    }
    else if(fun[i]==0)
         c=get_cost(i-1,j);
    else if((table[i-1][j-cost[i]]+fun[i])==table[i-1][j])
    {
        temp1=get_cost(i-1,j-cost[i])+cost[i];
        temp2=get_cost(i-1,j);
        if(temp1<=temp2)
            c=temp1;
        else
            c=temp2;
    }
    else if(table[i][j]==(table[i-1][j-cost[i]]+fun[i]))
        c=get_cost(i-1,j-cost[i])+cost[i];   
    else
        c=get_cost(i-1,j);
    return c;
}
int main()
{
    int budget,n,i,j,temp1,temp2,a;
    while(1)
    {
    scanf("%d",&budget);
    scanf("%d",&n);
    if(budget==0&&n==0)
        break;
    for(i=0;i<n;i++)
    {
        scanf("%d",&cost[i]);
        scanf("%d",&fun[i]);
    }
    for(i=0;i<n;i++)         // i handles fun
    {
        for(j=0;j<=budget;j++)   // j handles cost
        {
            if(i==0&&j==0)
               table[i][j]=0;
            else if(i==0&&j!=0)
            {
                if(j<cost[i])
                   table[i][j]=0;
                else
                   table[i][j]=fun[i];                  
            }
            else if(i!=0&&j<cost[i])
               table[i][j]=table[i-1][j];
            else
            {
                temp1=table[i-1][j];
                temp2=table[i-1][j-cost[i]]+fun[i];
                if(temp1>=temp2)
                  table[i][j]=temp1;  
                else if(temp1<temp2)
                   table[i][j]=temp2;                                                  
            }
        }                  
    }
    a=get_cost(n-1,budget);
    printf("%d %d\n",a,table[n-1][budget]);       
    }
    return 0;
}
