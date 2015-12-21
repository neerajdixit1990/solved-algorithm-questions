#include<stdio.h>
int main()
{
    long long int no_trees,wood_needed,sum,tree_len[1000002],i,max_len,max,min,c1,c2;
    scanf("%lld",&no_trees);
    scanf("%lld",&wood_needed);
    sum=0;max=0;min=100000000;
    for(i=0;i<no_trees;i++)
    {
        scanf("%lld",&tree_len[i]);
        sum=sum+tree_len[i];
        if(tree_len[i]>max)
            max=tree_len[i];
        else
        {
            if(tree_len[i]>min)
                min=tree_len[i];
        }
    }
    sum=sum-wood_needed;
    max_len=sum/no_trees;
    
    sum=0;
    for(i=0;i<no_trees;i++)
    {
        if(tree_len[i]<=max_len)
            continue;
        sum=sum+tree_len[i]-max_len;
    }
    
    while(1)
    {
        if(sum>wood_needed)
            min=max_len;
        else if(sum<wood_needed)
            max=max_len;
        else
            break;
        max_len=(min+max)/2;
        sum=0;
        for(i=0;i<no_trees;i++)
        {
            if(tree_len[i]<=max_len)
                continue;
            sum=sum+tree_len[i]-max_len;
        }
        c1=sum; sum=0;
        for(i=0;i<no_trees;i++)
        {
            if(tree_len[i]<=(max_len+1))
                continue;
            sum=sum+tree_len[i]-(max_len+1);
        }
        c2=sum;
        if(c1>=wood_needed&&c2<wood_needed)
            break;
        sum=c1;
    }
    printf("%lld",max_len);
    
    return 0;
}
