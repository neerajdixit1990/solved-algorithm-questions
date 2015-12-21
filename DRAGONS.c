#include<stdio.h>
int main()
{
    char input[5000];
    int test_cases,i,j,flag=0;
    scanf("%d",&test_cases);
    for(i=0;i<test_cases;i++)
    {
        scanf("%s",input);
        flag=0;
        for(j=0;input[j]!='\0';j++)
            if(input[j]=='D'||input[j]=='d')
            {   flag=1;
                break;
            }
        if(flag==0)
            printf("Possible\n");
        else
            printf("You shall not pass!\n");
    }
    return 0;
}
