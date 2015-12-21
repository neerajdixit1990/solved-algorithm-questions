#include<stdio.h>
int main()
{
    int already[6],one_ingre[6],status[6],i,flag,max_val,index,ans[6];
    float maxi[6],temp;
    while(1)
    {
        flag=0;
        for(i=0;i<4;i++)
        {    
             scanf("%d",&already[i]);
             if(already[i]==-1)
                 flag=1;
        }
        for(i=0;i<4;i++)
        {    
             scanf("%d",&one_ingre[i]);
             if(one_ingre[i]==-1)
                 flag=1;
        }
        if(flag==1)
            break;
        temp=-1;
        for(i=0;i<4;i++)
        {
            maxi[i]=(float)already[i]/(float)one_ingre[i];
            if(maxi[i]>temp)
            {   
                temp=maxi[i];
                index=i;
            }
        }
        if((already[index]%one_ingre[index])==0)
            max_val=already[index]/one_ingre[index];
        else
            max_val=(already[index]/one_ingre[index])+1;
        for(i=0;i<4;i++)
            ans[i]=max_val*one_ingre[i]-already[i];
        printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
    }
    return 0;
}
