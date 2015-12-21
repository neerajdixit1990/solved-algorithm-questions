#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int test_cases,i,j,len=0,currlength=0,maxlength=-1,no_words=0,group_length=1,temp;
    char input[1020]={'\0'};
	scanf("%d",&test_cases);
	for(i=1;i<=test_cases;i++)
	{   len=0;
		currlength=0;
        maxlength=-1;
        no_words=0;
		group_length=1;
		gets(input);
		len=strlen(input);
        for(j=0;j<=len;j++)
        {
            if(input[j]==32||input[j]=='\0'||input[j]=='\n')
			{
				if(no_words==currlength)
					group_length++;
				else
				{
					currlength=no_words;
					if(group_length>maxlength)
						maxlength=group_length;
					group_length=1;
				}
				no_words=0;
			}
			else
				no_words++;
        }
        printf("%d",maxlength);
    }
    return 0;
}
