#include<stdio.h>
#include<string.h>
int main()
{
    int test_cases,n,i,j,possible_friends[52],index,k,temp;
    char input[52][52],pf[52][52];
    scanf("%d",&test_cases);
    while(test_cases--)
    {
        scanf("%s",&input[0][0]);
        n=strlen(input[0]);
        for(i=0;i<n;i++)
            pf[0][i]='N';
        pf[0][n]='\0';
        if(n==1)
        {
            printf("0 0\n");
            continue;
        }
        for(i=0;i<n;i++)
            possible_friends[i]=0;
        for(i=1;i<n;i++)
        {   scanf("%s",input[i]);
            strcpy(pf[i],pf[0]);
        }
        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(input[i][j]=='N')
                {
                    for(k=0;k<n;k++)
                    {
                        if(input[k][i]=='Y'&&input[k][j]=='Y')
                        {   
                            if(pf[i][j]=='N')
                            {   possible_friends[j]++;
                                possible_friends[i]++;
                                pf[i][j]='Y';
                                pf[j][i]='Y';
                            }
                        }
                    }
                }
            }
        }
        temp=-1;
        index=-1;
        for(i=0;i<n;i++)
        {
            if(possible_friends[i]>temp)
            {
                temp=possible_friends[i];
                index=i;
            }
        }
        printf("%d %d\n",index,possible_friends[index]);
    }
    return 0;
}
