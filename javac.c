#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char input[102]={'\0'},aux[240]={'\0'};
    int sep_present=0,cap_present=0,i,j,k,len,flag=0;
    while(scanf("%s",input)!=EOF)
    {
        sep_present=0;
        flag=0;
        cap_present=0;
        len=strlen(input);
        if((input[0]>=65&&input[0]<=90)||input[0]=='_'||input[len-1]=='_'||strstr(input,"__"))
            flag=1;
        if(flag==0)
        {
            for(i=0;i<len;i++)
            {
                if(input[i]>=65&&input[i]<=90)
                    cap_present=1;
                else if(input[i]=='_')
                    sep_present=1;
            }
        }
        if((cap_present==1&&sep_present==1)||flag==1)
            printf("\nError!");
        else if(cap_present==0&&sep_present==0)
             printf("\n%s",input);
        else if(cap_present==1&&sep_present==0)     // Java style
        {
             for(j=0,k=0;j<len;)
             {
                 if(input[j]>=65&&input[j]<=90)
                 {    aux[k++]='_';
                      aux[k++]=input[j++]+32;
                 }
                 else
                     aux[k++]=input[j++];
             }
             aux[k]='\0';
             printf("\n%s",aux);
        }
        else                    // C++ style
        {
            for(j=0,k=0;j<len;)
             {
                 if(input[j]=='_')
                 {   aux[k++]=input[++j]-32;
                     j++;
                 }
                 else
                     aux[k++]=input[j++];
             }
             aux[k]='\0';
             printf("\n%s",aux);
        }
    }
    return 0;
}
