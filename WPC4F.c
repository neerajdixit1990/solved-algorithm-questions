#include<stdio.h>
int main()
{
    int test_cases,i,n,input[21][3],j,k,tab[21][3],first,second;
    scanf("%d",&test_cases);
    for(i=0;i<test_cases;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
            scanf("%d%d%d",&input[j][0],&input[j][1],&input[j][2]);
        tab[0][0]=input[0][0];
        tab[0][1]=input[0][1];
        tab[0][2]=input[0][2];
        for(j=1;j<n;j++)
        {
            for(k=0;k<3;k++)
            {
                if(k==0)
                {
                    first=input[j][0]+tab[j-1][1];
                    second=input[j][0]+tab[j-1][2];
                }
                else if(k==1)
                {
                    first=input[j][1]+tab[j-1][0];
                    second=input[j][1]+tab[j-1][2];
                }
                else
                {
                    first=input[j][2]+tab[j-1][0];
                    second=input[j][2]+tab[j-1][1];
                }
                if(first>second)
                    tab[j][k]=second;
                else
                    tab[j][k]=first;
            }
        }
        first=tab[n-1][0];
        for(j=1;j<3;j++)
            if(first>tab[n-1][j])
                first=tab[n-1][j];
        printf("%d\n",first);
    }
    return 0;
}
