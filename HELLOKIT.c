#include<stdio.h>
#include<string.h>
int main()
{
    char input[50];
    int factor,len,rep,i,j;
    while(1)
    {
        scanf("%s",input);
        len=strlen(input);
        if((len==1)&&input[0]=='.')
            break;
        scanf("%d",&factor);
        rep=len*factor;
        for(i=0;i<len;i++)
        {
            for(j=i;j<rep;j++)
                printf("%c",input[j%len]);
            for(j=0;j<i;j++)
                printf("%c",input[j]);
            printf("\n");
        }
    }
    return 0;
}
