#include <stdio.h>
#include<string.h>
int main()
{
    char input[84],group[84];
    int previous[84],first,second,third,len,first_previous,second_previous,third_previous;
    int first_len,second_len,third_len,i,j,k;
    while(1)
    {
        scanf("%d%d%d",&first,&second,&third);
        first_previous=-1;
        second_previous=-1;
        third_previous=-1;
        first_len=0;
        second_len=0;
        third_len=0;
        if(first==0&&second==0&&third==0)
            break;
        scanf("%s",input);
        len=strlen(input);
        for(i=0;i<len;i++)
        {
            if(input[i]=='_')
            {   
                group[i]='3';
                third_previous=i;
                third_len++;
            }    
            else if(input[i]>='a'&&input[i]<='i')
            {
                group[i]='1';
                first_previous=i;
                first_len++;
            }
            else if(input[i]>='j'&&input[i]<='r')
            {
                group[i]='2';
                second_previous=i;
                second_len++;
            }
            else if(input[i]>='s'&&input[i]<='z')
            {
                group[i]='3';
                third_previous=i;
                third_len++;
            }
        }
        for(i=0;i<len;i++)
        {
            if(group[i]=='1')
            {
                previous[i]=first_previous;
                first_previous=i;
            }
            else if(group[i]=='2')
            {
                previous[i]=second_previous;
                second_previous=i;
            }
            else if(group[i]=='3')
            {
                previous[i]=third_previous;
                third_previous=i;
            }
        }
        if(first_len!=0)
            first=first%first_len;
        if(second_len!=0)
        second=second%second_len;
        if(third_len!=0)
            third=third%third_len;
        printf("\n");
        for(i=0;i<len;i++)
        {
            if(group[i]=='1')
            {
                k=i;
                for(j=0;j<first;j++)
                    k=previous[k];
                printf("%c",input[k]);
            }
            else if(group[i]=='2')
            {
                 k=i;
                for(j=0;j<second;j++)
                    k=previous[k];
                printf("%c",input[k]);
            }
            else if(group[i]=='3')
            {
                 k=i;
                for(j=0;j<third;j++)
                    k=previous[k];
                printf("%c",input[k]);
            }
        }
    }
    return 0;
}
