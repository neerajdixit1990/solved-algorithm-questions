#include<stdio.h>
int main()
{
    int n,i,input[1500],temp,dec,j;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        dec=1;
        for(i=0;i<n;i++)
            scanf("%d",&input[i]);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(input[i]>input[j])
                {
                    temp=input[i];
                    input[i]=input[j];
                    input[j]=temp;
                }
            }
        }
        if(input[0]!=0)
            dec=0;
        else if(input[n-1]<1322)
            dec=0;
        else
        {
            for(i=1;i<n;i++)
            {
                if((input[i]-input[i-1])>200)
                {
                    dec=0;
                    break;
                }
            }
        }
        if(dec==0)
            printf("IMPOSSIBLE\n");
        else
            printf("POSSIBLE\n");
    } 
    return 0;
}
