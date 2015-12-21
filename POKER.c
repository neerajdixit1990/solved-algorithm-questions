#include<stdio.h>
#include<stdlib.h>
int main()
{
    char input[6][5],temp;
    int *count,same_suite,highest_rep,asc_order,i,test_cases,j,t,rep;
    scanf("%d",&test_cases);
    for(i=0;i<test_cases;i++)
    {
        same_suite=1;
        highest_rep=-1;
        asc_order=0;
        count=(int *)calloc(1,sizeof(int)*18);
        for(j=0;j<5;j++)
            scanf("%s",input[j]);
        temp=input[0][1];
        for(j=1;j<5;j++)
            if(temp!=input[j][1])
                same_suite=0;
        for(j=0;j<5;j++)
        {
            if(input[j][0]>='2'&&input[j][0]<='9')
            {   
                count[input[j][0]-48]++;
                if(count[input[j][0]-48]>highest_rep)
                    highest_rep=count[input[j][0]-48];
            }
            else if(input[j][0]=='A'||input[j][0]=='a')
            {   
                count[1]++;
                count[14]++;
                if(count[1]>highest_rep)
                    highest_rep=count[1];
            }
            else if(input[j][0]=='T'||input[j][0]=='t')
            {   
                count[10]++;
                if(count[10]>highest_rep)
                    highest_rep=count[10];
            }
            else if(input[j][0]=='J'||input[j][0]=='j')
            {   
                count[11]++;
                if(count[11]>highest_rep)
                    highest_rep=count[11];
            }
            else if(input[j][0]=='Q'||input[j][0]=='q')
            {   
                count[12]++;
                if(count[12]>highest_rep)
                    highest_rep=count[12];
            }
            else if(input[j][0]=='K'||input[j][0]=='k')
            {   
                count[13]++;
                if(count[13]>highest_rep)
                    highest_rep=count[13];
            }
        }
        for(j=1;j<=14;j++)
        {
            if(count[j]==1)
            {
                t=0;
                while(t<5)
                {
                    if(count[j]==0||count[j]!=1)
                        break;
                    t++;
                    j++;
                }
                if(t==5)
                {   
                    asc_order=1;
                    break;
                }
            }
        }
        // decision making
        if(same_suite==1)
        {
            if(asc_order==0)
                printf("flush\n");
            else
            {
                t=10;
                while(t<15)
                {
                    if(count[t]!=1)
                        break;
                    t++;
                }
                if(t==15)
                    printf("royal flush\n");
                else
                    printf("straight flush\n");
            }
        }
        else
        {
            if(highest_rep==4)
                printf("four of a kind\n");
            else if(highest_rep==3)
            {
                 t=1;
                 while(t<15)
                 {   
                     if(count[t]==2)
                     {
                          t=20;
                          break;
                     }
                     t++;
                 }    
                 if(t==20)
                     printf("full house\n");
                 else
                     printf("three of a kind\n");
            }
            else if(highest_rep==2)
            {
                 t=1;
                 rep=0;
                 while(t<14)
                 {  
                     if(count[t]==2)
                     {
                         rep++;
                         if(rep==2)
                             break;
                     }
                     t++;
                 }
                 if(rep==2)
                     printf("two pairs\n");
                 else if(rep==1)
                     printf("pair\n");
            }
            else if(highest_rep==1&&asc_order==0)
                 printf("high card\n");
            else if(highest_rep==1&&asc_order==1)
                 printf("straight\n");
        }
    }
    return 0;
}
