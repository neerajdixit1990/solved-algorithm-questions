#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,rep[210]={0},i,input[210],flag[210]={0},count,len,t,temp,j;
    long long int k,m;
    char str[210],output[210];
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<=n;i++)
            rep[i]=0;
        for(i=1;i<=n;i++)
            scanf("%d",&input[i]);
        for(i=1;i<=n;i++)
        {
            if(rep[i]==0)
            {
                count=1;
                flag[i]=1;
                t=i;
                while(1)
                {
                    t=input[t];
                    if(flag[t]==1)
                        break;
                        flag[t]=1;
                        count++;
                }
                rep[i]=count;
                flag[i]=0;
                t=i;
                while(1)
                {
                    t=input[t];
                    if(flag[t]==0)
                        break;
                    flag[t]=0;
                    rep[t]=count;
                }
            }
        }
        while(1)
        {
            scanf("%lld",&k);
            if(k==0)
                break;
		    i=1;
		    scanf("%c",&str[101]);
            while(scanf("%c",&str[i]))
            {
                if(str[i++]==10)
                    break;
            }
            str[i]='\0';
		    len=i-1;
            if(k==0)
                break;
            for(i=0;i<=n;i++)
                output[i]=' ';
            for(i=1;i<len;i++)
            {
                m=(long long int)(k%(long long int)rep[i]);
                temp=i;
                for(j=0;j<m;j++)
                    temp=input[temp];
                output[temp]=str[i];
            }
            for(i=1;i<=n;i++)
                printf("%c",output[i]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
