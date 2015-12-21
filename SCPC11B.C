#include<stdio.h>
int main()
{
    int n,max[11],count[11],min,i,input,dec;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        min=1;
        dec=1;
        for(i=0;i<11;i++)
        {
            count[i]=0;
            max[i]=-1;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&input);
            if(input==0)
                min=0;
            if(input<=200)
            {
                count[1]++;
                if(input>max[1])
                    max[1]=input;
            }
            else if(input<=400)
            {
                count[2]++;
                if(input>max[2])
                    max[2]=input;
            }
            else if(input<=600)
            {
                count[3]++;
                if(input>max[3])
                    max[3]=input;
            }
            else if(input<=800)
            {
                count[4]++;
                if(input>max[4])
                    max[4]=input;
            }
            else if(input<=1000)
            {
                count[5]++;
                if(input>max[5])
                    max[5]=input;
            }
            else if(input<=1200)
            {
                count[6]++;
                if(input>max[6])
                    max[6]=input;
            }
            else
            {
                count[7]++;
                if(input>max[7])
                    max[7]=input;
            }
        }
        if(max[7]<1322)
            dec=0;
        else if(min!=0)
            dec=0;
        else
        {
            for(i=1;i<=7;i++)
            {   
                if(count[i]==0)
                {
                    dec=0;
                    break;
                }   
            }
            if(dec==1)
            {
                for(i=2;i<=7;i++)
                {
                    if((max[i]-max[i-1])>200)
                    {
                        dec=0;
                        break;
                    }
                }
            }
        }
        if(dec==1)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
