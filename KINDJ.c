#include<stdio.h>
#include<string.h>
int main()
{
    int flag=1,count,len,i,letter_present,exi=0;
    char input[1020],temp;
    while(1)                    //while(getline(cin,s,'\n')
    {
        i=0;
        while(1)
        {
            if(scanf("%c",&temp)==EOF)
            {   
                exi=1;
                break;
            }
            if(temp=='\n')
            {
                input[i]='\0';
                len=i;
                break;
            }
            input[i++]=temp;
        }
        if(exi==1)
            break;
        if(flag!=1)
        {   printf("\n");
            flag=0;
        }
        count=0;
        letter_present=0;
        for(i=0;i<len;i++)
        {
            if(input[i]==' ')
            {   
                if(letter_present==1)
                {
                    count++;
                    letter_present=0;
                }
            }
            else
            {
                if(input[i]>='A'&&input[i]<='Z')
                    letter_present=1;
                else if(input[i]>='a'&&input[i]<='z')
                    letter_present=1;
            }
        }
        printf("%d",count);
    }
    return 0;
}
