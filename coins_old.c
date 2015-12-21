#include <stdio.h>
find_max(long long int input)
{
    long long int first,second,third;
    if(input==0)
        return 0;
    else if(input==1)
        return 1;
    else if(input==2)
        return 2;
    else if(input==3)
        return 3;
    else if(input==4)
        return 4;
    else
    {
        first=find_max((long long int)(input/2));
        second=find_max((long long int)(input/3));
        third=find_max((long long int)(input/4));
        first=first+second+third;
        if(first>input)
            return first;
        else
            return input;
    }
}
int main()
{
    long long int input,ans;
    while(scanf("%lld",&input)!=EOF)
    {
        ans=find_max(input);
        printf("%lld\n",ans);
    }
    return 0;
}
