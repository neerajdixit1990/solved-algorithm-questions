#include<stdio.h>
int main()
{
    int g,b,ans;
    while(1)
    {
        scanf("%d",&g);
        scanf("%d",&b);
        if(g==-1&&b==-1)
            break;
        if(g==0)
            ans=b;
        else if(b==0)
            ans=g;
        else if(g<b)
        {
            ans=b/(g+1);
            if(b%(g+1)!=0)
                ans++;
        }
        else
        {
            ans=g/(b+1);
            if(g%(b+1)!=0)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
