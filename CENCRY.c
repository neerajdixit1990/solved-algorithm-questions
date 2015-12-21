#include<stdio.h>
int main()
{
    char vowel[6]="aeiou",consonant[22]="bcdfghjklmnpqrstvwxyz";
    char input[50010],output[50010];
    int test_cases,i,count[26],j,len,flag,k,l;
    scanf("%d",&test_cases);
    for(i=0;i<test_cases;i++)
    {
        for(j=0;j<26;j++)
            count[j]=0;
        l=0;
        scanf("%s",&input);
        len=strlen(input);
        for(j=0;j<len;j++)
        {
            if(input[j]=='a'||input[j]=='e'||input[j]=='i'||input[j]=='o'||input[j]=='u')
                flag=1;
            else
                flag=2;
            if(flag==1)
            {
                for(k=0;;k++)
                    if(input[j]==vowel[k])
                        break;
                k=k+count[input[j]-97]*5;
                k=k%21;
                output[l++]=consonant[k];
            }
            else
            {
                for(k=0;;k++)
                    if(input[j]==consonant[k])
                        break;
                k=k+count[input[j]-97]*21;
                k=k%5;
                output[l++]=vowel[k];
            }
            count[input[j]-97]++;
        }
        output[l]='\0';
        printf("%s\n",output);
    }
    return 0;
}
