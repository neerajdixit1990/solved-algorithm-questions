#include<stdio.h>
#include<string.h>
int main()
{
    int low,high,temp,i;
    char response[6];
    scanf("%d%d",&low,&high);
    while(1)
    {
        if((high-low)>4)
        {
            temp=(high-low)/4;
            for(i=0;(high-low)>4;i++)
            {
                printf("%d\n",low);
                fflush(stdout);
                scanf("%s",response);
                if(response[0]=='W')
                    break;
                else if(response[0]=='H')
                    high=high-temp;
                else
                    low=low+temp;
            }
        }
        else
        {
            for(i=0;i<5;i++)
            {
                printf("%d\n",low+i);
                fflush(stdout);
                scanf("%s",response);
                if(response[0]=='W')
                    break;
            }
        }
    }
    return 0;
}
