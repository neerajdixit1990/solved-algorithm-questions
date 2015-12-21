#include<stdio.h>
void find_greatest(int *vote_count,int *status,int candidates,int *winner1,int *winner2)
{
    int temp=-32767,i,winner=-1;
    for(i=1;i<=candidates;i++)
    {
        if(vote_count[i]>temp&&status[i]==0)
        {
            temp=vote_count[i];
            winner=i;
        }
    }
    status[winner]=1;
    *winner1=winner;
    temp=-32767;  winner=-1;
    for(i=1;i<=candidates;i++)
    {
        if(vote_count[i]>temp&&status[i]==0)
        {
            temp=vote_count[i];
            winner=i;
        }
    }
    *winner2=winner;
}
int find_winner(int cand1,int cand2,int preference[102][102],int voters,int candidates)
{
    int i,j,votes_1=0,votes_2=0;
    for(i=1;i<=voters;i++)
    {
        for(j=1;j<=candidates;j++)
        {
            if(preference[i][j]==cand1)
            {   votes_1++;
                break;
            }
            else if(preference[i][j]==cand2)
            {   votes_2++;                          
                break;
            }
        }
    }
    if(votes_1>votes_2)
        return cand1;
    else
        return cand2;
}
int main()
{
    int test_cases,candidates,voters,i,preference[102][102],j,k,vote_count[102],status[102],winner,cand1,cand2,round;
    scanf("%d",&test_cases);
    for(i=0;i<test_cases;i++)
    {
        scanf("%d",&candidates);
        scanf("%d",&voters);
        winner=-1;
        round=1;
        for(j=1;j<=candidates;j++)
        {   vote_count[j]=0;
            status[j]=0;
        }
        for(j=1;j<=voters;j++)
        {
            for(k=1;k<=candidates;k++)
                scanf("%d",&preference[j][k]);                     
        }
        for(j=1;j<=voters;j++)
            vote_count[preference[j][1]]++;
        for(j=1;j<=candidates;j++)
            if(vote_count[j]>(voters/2))
                winner=j;               
        if(winner==-1)
        {
            round=2;
            find_greatest(vote_count,status,candidates,&cand1,&cand2);
            winner=find_winner(cand1,cand2,preference,voters,candidates);
        }  
        printf("%d %d\n",winner,round);              
    }
    return 0;
}
