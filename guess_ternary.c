#include<stdio.h>
#include<string.h>
int main()
{
    int low,high,temp;
    char response[6];
    scanf("%d%d",&low,&high);
    low--;
    high++;
    while(1)
    {
        if((high-low)>3)
            temp=(high-low)/3;
        else
            temp=1;
        printf("%d\n",low+temp);
        fflush(stdout);
        scanf("%s",response);
        if(strcmp(response,"WIN")==0)
            break;
        else if(strcmp(response,"HIGH")==0)
        {   high=low+temp;
            continue;
        }
        else
            low=low+temp;
    
        printf("%d\n",high-temp);
        fflush(stdout);
        scanf("%s",response);
        if(strcmp(response,"WIN")==0)
            break;
        else if(strcmp(response,"HIGH")==0)
            high=high-temp;   
        else
            low=high-temp;
    }
    return 0;
}
