#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int test_cases,i,change_index,j,len;
    char input[100]={'\0'};
    scanf("%d",&test_cases);
    for(i=1;i<=test_cases;i++)
    {
        scanf("%d",&change_index);
        scanf("%s",input);
        len=strlen(input);
        for(j=change_index-1;j<len;j++) 
            input[j]=input[j+1];
        input[len-1]='\0';
        printf("\n%d",i);
        printf(" %s",input);
    }
    return 0;
}
