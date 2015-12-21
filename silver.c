#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int input,ans;
    while(1)
    {
        scanf("%d",&input);
        if(input==0)
            break;
        ans=0;
        if((input&(input-1))==0)
        {
            while(input!=0)
            {
                input=input>>1;
                ans++;
            }
            ans--;
        }
        else
            ans=(int)(log(input)/log(2));
        printf("%d\n",ans);
    }
    return 0;
}
