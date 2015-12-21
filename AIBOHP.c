#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int minim(int a,int b,int c)
{
    if(a<b)
    {
        if(c<a)
            return c;
        else
			return a;
    }
    else
    {
        if(b>c)
            return c;
        else
			return b;
	}
}
int main()
{
    int test_cases,len,i,j,k,**tab;
    char first[6010]={'\0'},second[6010]={'\0'};
    scanf("%d",&test_cases);
    tab=(int **)malloc(sizeof(int *)*6010);
    for(i=0;i<6010;i++)
        tab[i]=(int *)malloc(sizeof(int)*6010);
    for(i=0;i<6010;i++)
    {    tab[0][i]=i;
         tab[i][0]=i;
    }
    for(k=1;k<=test_cases;k++)
    {
        scanf("%s",first);
        len=strlen(first);
        second[len]='\0';
        for(i=0,j=len-1;i<len;i++)
            second[j--]=first[i];
        printf("\n");
        for(i=0;i<len;i++)
            printf("%c",second[i]);
        printf("\n");
        len=strlen(first);
        for(i=1;i<=len;i++)
        {
            for(j=1;j<=len;j++)
            {
				if(second[i-1]!=first[j-1])
					tab[i][j]=minim(tab[i][j-1]+1,tab[i-1][j-1]+1,tab[i-1][j]+1);
				else
					tab[i][j]=minim(tab[i][j-1]+1,tab[i-1][j-1],tab[i-1][j]+1);
            }
        }
        for(i=1;i<=len;i++)
        {   printf("\n");
            for(j=1;j<=len;j++)
                printf("%d ",tab[i][j]);
        }
    }
    return 0;
}
