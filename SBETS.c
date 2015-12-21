#include<stdio.h>
#include<string.h>
int main()
{
    int test_cases,i,score1,score2,j,count[20],t[5];
    char teams[20][5],first[5],second[5];
    scanf("%d",&test_cases);
    for(i=0;i<test_cases;i++)
    {
        count_teams=0;
        for(j=0;j<16;j++)
        {
            scanf("%s",first);
            scanf("%s",second);
            scanf("%d",&score1);
            scanf("%d",&score2);
            for(k=0;k<count_teams;k++)
            {
                if(strcmp(first,teams[k])==0)
                {    count[k]++;
                     break;
                }
            }
            if(k>=count_teams)
            {
                strcpy(teams[count_teams],first);
                count_teams++;
            }
            for(k=0;k<count_teams;k++)
            {
                if(strcmp(second,teams[k])==0)
                {    count[k]++;
                     break;
                }
            }
            if(k>=count_teams)
            {
                strcpy(teams[count_teams],second);
                count_teams++;
            }
        }
        k=0;
        for(j=0;j<16;j++)
        {
            if(count[j]==4)
                t[k++]=j;    
        }
        for(j=0;j<16;j)
    }
    return 0;
}
