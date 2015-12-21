#include<stdio.h>
int main()
{
    char input[1020];
    int i=1,count,j,len;
    while(scanf("%s",input)!=EOF)
    {
        count=0;
        len=strlen(input);
        for(j=0;j<len;j++)
        {
            if(count%2)
            {
                if(input[j]=='0')
                    count++;
            }
            else
            {
                if(input[j]=='1')
                    count++;
            }
        }
        printf("Game #%d: %d\n",i,count);
        i++;
    }
    return 0;
}
