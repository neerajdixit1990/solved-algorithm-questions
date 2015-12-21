#include<stdio.h>
int main()
{
    int first,second,mid;
    char result[9];
    scanf("%d",&first);
    scanf("%d",&second);
    while(first<=second)
    {
        mid=(first+second)/2;
        printf("%d\n",mid);
        fflush(stdout);
        scanf("%s",result);
        if(result[0]=='W')
            break;
        else if(result[0]=='L')
            first=mid+1;
        else
            second=mid-1;
    }
    return 0;
}
