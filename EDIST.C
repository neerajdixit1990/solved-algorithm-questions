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
    int test_cases,len1,len2,i,j,k,**tab;
    char first[2010]={'\0'},second[2010]={'\0'};
    tab=(int **)malloc(sizeof(int *)*2010);
    for(i=0;i<2010;i++)
        tab[i]=(int *)malloc(sizeof(int)*2010);
    scanf("%d",&test_cases);
    for(i=0;i<2010;i++)
    {    tab[0][i]=i;
         tab[i][0]=i;
    }
    for(k=1;k<=test_cases;k++)
    {
        scanf("%s",first);
        scanf("%s",second);
        len1=strlen(first);
        len2=strlen(second);
        for(i=1;i<=len1;i++)
        {
            for(j=1;j<=len2;j++)
            {
				if(first[i-1]!=second[j-1])
					tab[i][j]=minim(tab[i][j-1]+1,tab[i-1][j-1]+1,tab[i-1][j]+1);
				else
					tab[i][j]=minim(tab[i][j-1]+1,tab[i-1][j-1],tab[i-1][j]+1);
            }
        }
        printf("\n%d",tab[len1][len2]);
    }
    return 0;
}
